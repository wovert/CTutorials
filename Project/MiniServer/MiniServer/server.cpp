﻿#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
	#include <Windows.h>
	#include <WinSock2.h>
	// load dynamic library
	#pragma comment(lib, "ws2_32.lib")
#else
	#include <unistd.h> // uni std
	#include <arpa/inet.h>
	#include <string.h>

	#define SOCKET int
	#define INVALID_SOCKET (SOCKET)(-0)
	#define SOCKET_ERROR (-1)
#endif

#include <stdio.h>
#include <vector>

#define SERVER_PORT 9002
#define SERVER_IP "127.0.0.1"

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
struct Login: public DataHeader {
	Login() {
		cmd = CMD_LOGIN;
		dataLength = sizeof(Login);
	}
	char username[32];
	char password[32];
};

struct LoginResult: public DataHeader{
	LoginResult() {
		cmd = CMD_LOGIN_RESULT;
		dataLength = sizeof(LoginResult);
		result = 0;
	}
	int result;
};

struct Logout: public DataHeader {
	Logout() {
		cmd = CMD_LOGOUT;
		dataLength = sizeof(Logout);
	}
	char username[32];
};

struct LogoutResult: public DataHeader {
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

// 客户端连接
vector<SOCKET> g_clients;

int processor(SOCKET _cSock) {
	// 缓冲区
	char recvMsg[1024] = "";
	int nLen = (int)recv(_cSock, (char *)&recvMsg, sizeof(DataHeader), 0);
	printf("nLen=%d\n", nLen);
	DataHeader* header = (DataHeader*)recvMsg;

	if (nLen <= 0) {
		printf("客户端<Socket=%d>已退出，任务结束\n", _cSock);
		return -1;
	}

	switch (header->cmd) {
	case CMD_LOGIN: {
		recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		Login* login = (Login *)recvMsg;

		printf("收到<Socket=%d>命令: CMD_LOGIN 数据长度: %d, username=%s, passwod=%s\n", (int)_cSock,
			login->dataLength, login->username, login->password);

		// check username and password
		LoginResult ret;
		send(_cSock, (const char*)&ret, sizeof(LoginResult), 0);
	}
					break;
	case CMD_LOGOUT: {
		recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		Logout* logout = (Logout *)recvMsg;
		printf("收到<Socket=%d>命令: CMD_LOGOUT 数据长度: %d, username=%s\n", (int)_cSock,
			logout->dataLength, logout->username);

		LogoutResult ret;
		send(_cSock, (const char*)&ret, sizeof(LogoutResult), 0);
	}
					 break;
	default:
		DataHeader header = { CMD_ERROR, 0 };
		send(_cSock, (const char*)&header, sizeof(header), 0);
	}
	return 0;
}

int main2() {
#ifdef _WIN32
	// startup Windows socket 2.x env
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
#endif

	// 1. create socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 2. bind socket
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(SERVER_PORT); // host to net unsgined short
	
#ifdef _WIN32
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;
#else
	_sin.sin_addr.s_addr = INADDR_ANY;
#endif


	if (SOCKET_ERROR == bind(_sock, (sockaddr *)&_sin, sizeof(_sin))) {
		printf("绑定失败\n");
	}
	else {
		printf("绑定套接字成功\n");
	}

	// 3. listen port
	if (SOCKET_ERROR == listen(_sock, 5)) {
		printf("Listen failed\n");
	}
	else {
		printf("监听端口成功\n");
	}

	while (true) {
		
		// 伯克里套接字 BSD socket
		fd_set readFd; // 描述符（socket）集合
		fd_set writeFd;
		fd_set exceptFd;

		// 清理集合
		FD_ZERO(&readFd);
		FD_ZERO(&writeFd);
		FD_ZERO(&exceptFd);

		// 将描述符（socket）加入集合
		FD_SET(_sock, &readFd);
		FD_SET(_sock, &writeFd);
		FD_SET(_sock, &exceptFd);

		SOCKET maxSock = _sock;

		// 遍历访问客户端连接
		for (int n = (int)g_clients.size()-1; n >= 0; n--) {
			FD_SET(g_clients[n], &readFd);
			if (maxSock < g_clients[n]) {
				maxSock = g_clients[n];
			}
		}

		// int nfds fd_set集合中所有描述符(socket)的范围，而不是数量
		// 所有文件描述符最大值 +1 在Windows OS 这个值可以写0
		// *readfds, *writefds, exceptfds, *timeout
		// NULL: 永久等待直到有数据才会返回
		timeval t = { 1, 0 }; // 马上返回结果
		int ret = select(maxSock + 1, &readFd, &writeFd, &exceptFd, &t);
		if (ret < 0) {
			printf("select任务结束\n");
			break;
		}
		//printf("空闲时间处理其他业务...\n");

		// 判断描述符（socket）是否在集合中
		if (FD_ISSET(_sock, &readFd)) {
			FD_CLR(_sock, &readFd); // 在集合中清空描述符（socket）

			sockaddr_in clientAddr;
			int addrLen = sizeof(sockaddr_in);
			SOCKET _cSock = INVALID_SOCKET;

			// accept client
#ifdef _WIN32
			_cSock = accept(_sock, (sockaddr *)&clientAddr, &addrLen);
#else
			_cSock = accept(_sock, (sockaddr *)&clientAddr, (socklen_t *)&addrLen);
#endif

			if (INVALID_SOCKET == _cSock) {
				printf("access failed\n");
			}

			// 广播
			for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
				NewUserJoin userJoin;
				send(g_clients[n], (const char *)&userJoin, sizeof(NewUserJoin), 0);
			}

			g_clients.push_back(_cSock);
			printf("新的客户端连接 socket=%d, IP:%s\n", (int)_cSock, inet_ntoa(clientAddr.sin_addr));
		}

		// 遍历访问客户端连接
		//for (int n=0; n<readFd.fd_count; n++) {
		//	if (-1 == processor(readFd.fd_array[n])) {
		//		auto iter = find(g_clients.begin(), g_clients.end(), readFd.fd_array[n]);
		//		if (iter != g_clients.end()) {
		//			g_clients.erase(iter);
		//		}
		//	}
		//}
		for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
			if (FD_ISSET(g_clients[n], &readFd)) {
				if (-1 == processor(g_clients[n])) {
					// 自动推导类型
					auto iter = g_clients.begin() + n; //std::vector<SOCKET>::iterator iter = g_clients.begin() + n;
					if (iter != g_clients.end()) {
						g_clients.erase(iter);
					}
				}
			}
		}


	}
#ifdef _WIN32
	for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
		closesocket(g_clients[n]);
	}

	// 6. close socket
	closesocket(_sock);

	// clean Windows socket Env
	WSACleanup();
#else
	for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
		close(g_clients[n]);
	}
	close(_sock);
#endif
	return 0;
}