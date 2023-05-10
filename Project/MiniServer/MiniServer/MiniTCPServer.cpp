#include "MessageHeader.hpp"
#include "MiniTCPServer.hpp"

#include <stdio.h>
#define SERVER_PORT 9000
#define SERVER_PORT_2 9001
#define SERVER_IP "127.0.0.1"
#define LISTERN_NUMBER 5

using namespace std;

int main() {

	MiniTCPServer server;
	server.bindIpPort(SERVER_IP, SERVER_PORT);
	server.listenPort(LISTERN_NUMBER);

	MiniTCPServer server2;
	server2.bindIpPort(SERVER_IP, SERVER_PORT_2);
	server2.listenPort(LISTERN_NUMBER);

	while (server.isRun() || server.isRun()) {
		server.onRun();
		server2.onRun();
	}
	server.close();
	server2.close();

	printf("服务端已退出。\n");
	getchar();
	return 0;
}