﻿#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
	#include <Windows.h>
	#include <WinSock2.h>
#else
	#include <unistd.h> // uni std
	#include <arpa/inet.h>
	#include <string.h>

	#define SOCKET int
	#define INVALID_SOCKET (SOCKET)(-0)
	#define SOCKET_ERROR (-1)
#endif

#include <stdio.h>
#include <thread>

#define SERVER_PORT 9000
#define SERVER_IP "127.0.0.1"

// load dynamic library
#pragma comment(lib, "ws2_32.lib")

using namespace std;


struct DataPackage {
	int age;
	char name[32];
};

enum CMD {
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGOUT,
	CMD_LOGOUT_RESULT,
	CMD_NEW_USER_JOIN,
	CMD_ERROR
};

struct DataHeader {
	short cmd; // command
	short dataLength; // data length
};
struct Login : public DataHeader {
	Login() {
		cmd = CMD_LOGIN;
		dataLength = sizeof(Login);
	}
	char username[32];
	char password[32];
};

struct LoginResult : public DataHeader {
	LoginResult() {
		cmd = CMD_LOGIN_RESULT;
		dataLength = sizeof(LoginResult);
		result = 0;
	}
	int result;
};

struct Logout : public DataHeader {
	Logout() {
		cmd = CMD_LOGOUT;
		dataLength = sizeof(Logout);
	}
	char username[32];
};

struct LogoutResult : public DataHeader {
	LogoutResult() {
		cmd = CMD_LOGOUT_RESULT;
		dataLength = sizeof(LogoutResult);
		result = 0;
	}
	int result;
};

struct NewUserJoin : public DataHeader {
	NewUserJoin() {
		cmd = CMD_NEW_USER_JOIN;
		dataLength = sizeof(NewUserJoin);
		scok = 0;
	}
	int scok;
};

int processor(SOCKET _cSock) {
	// 缓冲区
	char recvMsg[1024] = "";
	int nLen = (int)recv(_cSock, (char *)&recvMsg, sizeof(DataHeader), 0);
	printf("recvMsg=%s\n", recvMsg);
	DataHeader* header = (DataHeader*)recvMsg;

	if (nLen <= 0) {
		printf("与服务器断开连接\n");
		return -1;
	}

	switch (header->cmd) {

		case CMD_LOGIN_RESULT: {
			recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			//LoginResult* loginResult = (LoginResult *)recvMsg;
			LoginResult* loginResult = (LoginResult *)header;
			printf("收到服务器消息: CMD_LOGIN_RESULT 数据长度: %d\n", loginResult->dataLength);
		}
		break;

		case CMD_LOGOUT_RESULT: {  
			recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			LogoutResult* logoutResult = (LogoutResult *)recvMsg;
			printf("收到服务器消息: CMD_LOGOUT_RESULT  数据长度: %d\n", logoutResult->dataLength);
		} 
		break;

		case CMD_NEW_USER_JOIN: {
			recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
			NewUserJoin* newUserJoin = (NewUserJoin *)recvMsg;
			printf("收到服务器消息: CMD_NEW_USER_JOIN  数据长度: %d\n", newUserJoin->dataLength);
		}
		break;
	}
	return 0;
};

bool g_bRun = true;

// 命令线程
void cmdThread(SOCKET _sock) {
	while (1) {
		char sendMsg[1024] = "";

		scanf("%s", sendMsg); // 阻塞
		if (0 == strcmp(sendMsg, "exit")) {
			g_bRun = false;
			printf("退出cmdThread线程\n");
			break;
		} else if(0 == strcmp(sendMsg, "login")) {
			Login login;
			strcpy(login.username, "admin");
			strcpy(login.password, "123456");
			printf("dataLength=%d\n", login.dataLength);
			send(_sock, (const char*)&login, login.dataLength, 0);
		} else if (0 == strcmp(sendMsg, "logout")) {
			Logout logout;
			strcpy(logout.username, "admin");
			send(_sock, (const char*)&logout, sizeof(logout), 0);
		}
		else {
			printf("收到不支持命令，请重新输入\n");
		}
	}
}

int main2() {
#ifdef _WIN32
	// startup Windows socket 2.x env
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
#endif
	// 1. create socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == _sock) {
		printf("Socket failed~\n");
		return -1;
	}
	else {
		printf("创建套接字!\n");
	}

	// 2. connect server
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET; // IPv4
	_sin.sin_port = htons(SERVER_PORT); // Port

#ifdef _WIN32
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // IP
#else
	_sin.sin_addr.s_addr = inet_addr("192.168.23.10"); // IP
#endif


	int ret = connect(_sock, (struct sockaddr *)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret) {
		printf("connect failed\n");
	}
	else {
		printf("connect server success!\n");
	}

	// 启动线程
	std:thread t1(cmdThread, _sock);
	t1.detach(); // 与主线程分离

	while (g_bRun) {

		fd_set fdReads;
		FD_ZERO(&fdReads);
		FD_SET(_sock, &fdReads);
		timeval t = { 1, 0 };
		int ret = (int)select(_sock+1, &fdReads, 0, 0, &t);
		if (ret < 0) {
			printf("select task1 end\n");
			break;
		}
		if (FD_ISSET(_sock, &fdReads)) {
			FD_CLR(_sock, &fdReads);
			if (-1 == processor(_sock)) {
				printf("select task2 end\n");
				break;
			}
		}
		//printf("空闲时间处理其他业务...\n");
		//Sleep(2000);
	}



#ifdef _WIN32
	// 4. close socket
	closesocket(_sock);
	// clean Windows socket Env
	WSACleanup();
#else
	close(_sock);
#endif
	return 0;
}