#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>

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
	CMD_ERROR
};

struct DataHeader {
	short cmd; // command
	short dataLenth; // data length
};
struct Login : public DataHeader {
	Login() {
		cmd = CMD_LOGIN;
		dataLenth = sizeof(Login);
	}
	char username[32];
	char password[32];
};

struct LoginResult : public DataHeader {
	LoginResult() {
		cmd = CMD_LOGIN_RESULT;
		dataLenth = sizeof(LoginResult);
		result = 0;
	}
	int result;
};

struct Logout : public DataHeader {
	Logout() {
		cmd = CMD_LOGOUT;
		dataLenth = sizeof(Logout);
	}
	char username[32];
};

struct LogoutResult : public DataHeader {
	LogoutResult() {
		cmd = CMD_LOGOUT_RESULT;
		dataLenth = sizeof(LogoutResult);
		result = 0;
	}
	int result;
};

int main() {
	// startup Windows socket 2.x env
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	// 1. create socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == _sock) {
		printf("Socket failed~\n");

	}
	else {
		printf("创建套接字!\n");
	}

	// 2. connect server
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET; // IPv4
	_sin.sin_port = htons(SERVER_PORT); // Port
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // IP

	int ret = connect(_sock, (struct sockaddr *)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret) {
		printf("connect failed\n");
	}
	else {
		printf("连接成功!\n");
	}

	// 3. receive from server data
	char recvMsg[1024] = "";
	char sendMsg[1024] = "";
	while (true) {
		scanf("%s", sendMsg);
		if (0 == strcmp(sendMsg, "exit")) {
			printf("收到退出命令eixt\n");
			break;
	
		} else if(0 == strcmp(sendMsg, "login")) {
			
			Login login;
			strcpy(login.username, "admin");
			strcpy(login.password, "123456");

			// send message to server
			send(_sock, (const char*)&login, sizeof(login), 0);

			// receive message from server
			LoginResult loginRet;
			recv(_sock, (char *)&loginRet, sizeof(loginRet), 0);

			printf("LoginResult: %d\n", loginRet.result);

		} else if (0 == strcmp(sendMsg, "logout")) {
			
			Logout logout;
			strcpy(logout.username, "admin");
			send(_sock, (const char*)&logout, sizeof(logout), 0);

			// receive message from server
			LogoutResult loginRet = {};
			recv(_sock, (char *)&loginRet, sizeof(loginRet), 0);

			printf("LogoutResult: %d\n", loginRet.result);
		}
		else {
			printf("收到不支持命令，请重新输入\n");
		}
	}

	// 4. close socket
	closesocket(_sock);

	// clean Windows socket Env
	WSACleanup();

	return 0;
}