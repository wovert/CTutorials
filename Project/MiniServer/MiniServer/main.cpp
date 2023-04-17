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
	printf("New client IP:%s\n", inet_ntoa(clientAddr.sin_addr));


	char recvMsg[1024] = "";
	while (true) {

		// 5. receive data from client
		int nLen = recv(_cSock, recvMsg, 1024, 0);
		if (nLen <= 0) {
			printf("Client closed\n");
			break;
		}
		printf("Client Message: %s\n", recvMsg);
		if (0 == strcmp(recvMsg, "getName")) {
			char sendMsg[] = "Hello, I'm Bob";
			send(_cSock, sendMsg, strlen(sendMsg) + 1, 0);
		}
		else if(0 == strcmp(recvMsg, "getAge")) {
			char sendMsg[] = "My age is 18old";
			send(_cSock, sendMsg, strlen(sendMsg) + 1, 0);
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