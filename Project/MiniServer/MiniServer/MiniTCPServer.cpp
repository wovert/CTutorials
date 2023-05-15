#include "MessageHeader.hpp"
#include "MiniTCPServer.hpp"

#include <stdio.h>
#include <thread>


#define SERVER_PORT 9000
#define SERVER_PORT_2 9001
#define SERVER_IP "127.0.0.1"
#define LISTERN_NUMBER 5

using namespace std;

bool g_bRun = true;

// 命令线程
void cmdThread() {
	while (1) {
		char sendMsg[1024] = "";
		//char sendMsg[1024] = "login";

		scanf("%s", sendMsg); // 阻塞
		if (0 == strcmp(sendMsg, "exit")) {
			g_bRun = false;
			printf("退出cmdThread线程\n");
			break;
		}
		else {
			printf("收到不支持命令，请重新输入\n");
		}
	}
}

int main() {

	MiniTCPServer server;
	server.bindIpPort(SERVER_IP, SERVER_PORT);
	server.listenPort(LISTERN_NUMBER);

	//MiniTCPServer server2;
	//server2.bindIpPort(SERVER_IP, SERVER_PORT_2);
	//server2.listenPort(LISTERN_NUMBER);

	std::thread t1(cmdThread);
	t1.detach(); // 与主线程分离

	//while (server.isRun()) {
	while (g_bRun) {
	//while (server.isRun() || server.isRun()) {
		server.onRun();
		//server2.onRun();
	}
	server.close();
	//server2.close();

	printf("服务端已退出。\n");
	getchar();
	return 0;
}