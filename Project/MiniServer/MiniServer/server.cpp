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
	CMD_LOGOUT,
	CMD_ERROR
};

struct DataHeader {
	short dataLenth; // data length
	short cmd; // command
};
struct Login {
	char username[32];
	char password[32];
};

struct LoginResult {
	int result;
};

struct Logout {
	char username[32];
};

struct LogoutResult {
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
		printf("Bind success\n");
	}

	// 3. listen port
	if (SOCKET_ERROR == listen(_sock, 5)) {
		printf("Listen failed\n");
	}
	else {
		printf("Listen success\n");
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


	char recvMsg[1024] = "";

	while (true) {
		DataHeader header = {};

		// 5. receive data from client
		int nLen = recv(_cSock, (char *)&header, sizeof(DataHeader), 0);
		if (nLen <= 0) {
			printf("Client closed\n");
			break;
		}
		printf("command: %d, dataLenth: %d\n", header.cmd, header.dataLenth);

		switch (header.cmd) {
			case CMD_LOGIN: {
				Login login = {};
				recv(_cSock, (char *)&login, sizeof(Login), 0);

				// check username and password
				LoginResult ret = {0};
				send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
				send(_cSock, (const char*)&ret, sizeof(LoginResult), 0);
			}
			break;
			case CMD_LOGOUT: {
				Logout logout = {};
				recv(_cSock, (char *)&logout, sizeof(Logout), 0);

				LogoutResult ret = { 0 };
				send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
				send(_cSock, (const char*)&ret, sizeof(LogoutResult), 0);
			}	
			break;
			default:
				header.cmd = CMD_ERROR;
				header.dataLenth = 0;
				send(_cSock, (const char*)&header, sizeof(DataHeader), 0);
		}
		if (0 == strcmp(recvMsg, "getInfo")) {
			DataPackage dp = { 18, "AI聊天" };
			printf("Client getInfo\n");
			send(_cSock, (const char*)&dp, sizeof(DataPackage), 0);
		}
		else {
			char sendMsg[] = "hello, I'm Server.";
			send(_cSock, sendMsg, strlen(sendMsg) + 1, 0);
		}

	}

	// 6. close socket
	closesocket(_sock);

	// clean Windows socket Env
	WSACleanup();

	return 0;
}