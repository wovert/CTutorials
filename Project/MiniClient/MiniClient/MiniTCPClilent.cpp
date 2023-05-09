#include "MessageHeader.hpp"
#include "MiniTCPClient.hpp"

#include <stdio.h>
#include <thread>



using namespace std;


// 命令线程
void cmdThread(MiniTCPClient* client) {
	while (1) {
		char sendMsg[1024] = "";

		scanf("%s", sendMsg); // 阻塞
		if (0 == strcmp(sendMsg, "exit")) {
			client->close();
			printf("退出cmdThread线程\n");
			break;
		}
		else if (0 == strcmp(sendMsg, "login")) {
			Login login;
			strcpy(login.username, "admin");
			strcpy(login.password, "123456");
			client->sendData(&login);
		}
		else if (0 == strcmp(sendMsg, "logout")) {
			Logout logout;
			strcpy(logout.username, "admin");
			client->sendData(&logout);
		}
		else {
			printf("收到不支持命令，请重新输入\n");
		}
	}
}

int main() {
	
	MiniTCPClient client;
	client.initSocket();
	client.connectServer(SERVER_IP, SERVER_PORT);


	// 启动UI线程
	std::thread t1(cmdThread, &client);
	t1.detach(); // 与主线程分离

	MiniTCPClient client2;
	client2.initSocket();
	client2.connectServer(SERVER_IP, SERVER_PORT_2);
	std::thread t2(cmdThread, &client2);
	t2.detach();

	MiniTCPClient client3;
	client3.initSocket();
	client3.connectServer(SERVER_IP, SERVER_PORT_3);
	std::thread t3(cmdThread, &client3);
	t3.detach();
	  

	while (client.isRun() || client2.isRun() || client3.isRun()) {
		client.onRun();
		client2.onRun();
		client3.onRun();
	}

	client.close();
	client2.close();
	client3.close();


	printf("已退出。\n");
	getchar();
	return 0;
}