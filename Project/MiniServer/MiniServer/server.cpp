#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

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
struct Login: public DataHeader {
	Login() {
		cmd = CMD_LOGIN;
		dataLenth = sizeof(Login);
	}
	char username[32];
	char password[32];
};

struct LoginResult: public DataHeader{
	LoginResult() {
		cmd = CMD_LOGIN_RESULT;
		dataLenth = sizeof(LoginResult);
		result = 0;
	}
	int result;
};

struct Logout: public DataHeader {
	Logout() {
		cmd = CMD_LOGOUT;
		dataLenth = sizeof(Logout);
	}
	char username[32];
};

struct LogoutResult: public DataHeader {
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
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 2. bind socket
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(SERVER_PORT); // host to net unsgined short
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (SOCKET_ERROR == bind(_sock, (sockaddr *)&_sin, sizeof(_sin))) {
		printf("Bind failed\n");
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

	// 4. accept
	sockaddr_in clientAddr;
	int addrLen = sizeof(sockaddr_in);
	SOCKET _cSock = INVALID_SOCKET;

	_cSock = accept(_sock, (sockaddr *)&clientAddr, &addrLen);
	if (INVALID_SOCKET == _cSock) {
		printf("Access failed\n");
	}
	printf("New client socket=%d, IP:%s\n", (int)_cSock, inet_ntoa(clientAddr.sin_addr));




	while (true) {
		// 缓冲区
		char recvMsg[1024] = "";

		//DataHeader header = {};

		//// 5. receive data from client
		//int nLen = recv(_cSock, (char *)&header, sizeof(DataHeader), 0);
		
		int nLen = recv(_cSock, (char *)&recvMsg, sizeof(DataHeader), 0);
		printf("recvMsg=%s\n", recvMsg);
		DataHeader* header = (DataHeader*)recvMsg;
		
		if (nLen <= 0) {
			printf("Client closed\n");
			break;
		}

		switch (header->cmd) {
			case CMD_LOGIN: {
				
				//recv(_cSock, (char *)&login + sizeof(DataHeader), sizeof(Login) - sizeof(DataHeader), 0);
								//printf("收到命令: CMD_LOGIN 数据长度: %d, username=%s, passwod=%s\n", 
				//	login.dataLenth, login.username, login.password);


				recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLenth - sizeof(DataHeader), 0);
				Login* login = (Login *)recvMsg;

				printf("收到命令: CMD_LOGIN 数据长度: %d, username=%s, passwod=%s\n",
					login->dataLenth, login->username, login->password);

				// check username and password
				LoginResult ret;
				send(_cSock, (const char*)&ret, sizeof(LoginResult), 0);
			}
			break;
			case CMD_LOGOUT: {
				
				//recv(_cSock, (char *)&logout + sizeof(DataHeader), sizeof(Logout) - sizeof(DataHeader), 0);
				//printf("收到命令: CMD_LOGOUT 数据长度: %d, username=%s\n",
				//	logout.dataLenth, logout.username);

				recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLenth - sizeof(DataHeader), 0);
				Logout* logout = (Logout *)recvMsg;
				printf("收到命令: CMD_LOGOUT 数据长度: %d, username=%s\n",
					logout->dataLenth, logout->username);

				LogoutResult ret;
				send(_cSock, (const char*)&ret, sizeof(LogoutResult), 0);
			}	
			break;
			default:
				DataHeader header = {CMD_ERROR, 0};
				send(_cSock, (const char*)&header, sizeof(header), 0);
		}

	}

	// 6. close socket
	closesocket(_sock);

	// clean Windows socket Env
	WSACleanup();

	return 0;
}