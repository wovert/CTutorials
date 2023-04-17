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
		printf("Socket succes!\n");
	}

	// 2. connect server
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET; // IPv4
	_sin.sin_port = htons(SERVER_PORT); // Port
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // IP

	int ret = connect(_sock, (struct sockaddr *)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret) {
		printf("connect failed");
	}
	else {
		printf("connect success!");
	}

	// 3. receive from server data
	char recvMsg[1024] = "";
	char sendMsg[1024] = "";
	while (true) {
		scanf("%s", sendMsg);
		if (0 == strcmp(sendMsg, "exit")) {
			break;
		}
		else {
			send(_sock, sendMsg, strlen(sendMsg) + 1, 0);
		}
		int clen = recv(_sock, recvMsg, 1024, 0);
		if (clen > 0) {
			printf("Server Message: %s\n", recvMsg);
		}
	}

	// 4. close socket
	closesocket(_sock);

	// clean Windows socket Env
	WSACleanup();

	return 0;
}