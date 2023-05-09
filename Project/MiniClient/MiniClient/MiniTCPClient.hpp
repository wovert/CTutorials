// .hpp编写函数的定义和实现
// 包含一次代码，定义宏防止同一个文件多次包含此文件的代码
#ifndef _MiniTCPClient_hpp_
#define _MiniTCPClient_hpp_


#ifdef _WIN32
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
#include <thread>

#define SERVER_PORT 9000
#define SERVER_PORT_2 9001
#define SERVER_PORT_3 9002
#define ERROR_CODE (-1)


#ifdef _WIN32
	#define SERVER_IP "127.0.0.1"
#else
	#define SERVER_IP "192.168.23.10"
#endif



class MiniTCPClient {
private:
	SOCKET _sock;
public:
	MiniTCPClient() {
		_sock = INVALID_SOCKET;
	}
	// 虚析构函数
	// 1.基类析构函数不定义为虚析构，当我们用基类指针指向子类对象的时候，只会调用基类析构函数
	// 2.当基类设置为虚析构，子类的析构函数会被调用，且子类的析构函数不需要设置为虚析构，孙子类的析构函数仍然会调用
	virtual ~MiniTCPClient() {
		this->close();
	}

	/**
	 * 初始化socket
	 */
	int initSocket() {

#ifdef _WIN32
		// 启动Win Sock 2.x环境
		WORD ver = MAKEWORD(2, 2);
		WSADATA dat;
		WSAStartup(ver, &dat);
#endif
		if (INVALID_SOCKET != this->_sock) {
			printf("<socket=%d>关闭旧连接。\n", this->_sock);
			this->close();
		}
		
		// 1. 建立 socket
		this->_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == this->_sock) {
			printf("建立socket失败。\n");
			return ERROR_CODE;
		}
		else {
			printf("建立socket成功。\n");
		}

	}
	/**
	 * 连接服务器
	 */
	int connectServer(const char* ip, const unsigned short port) {
		if (INVALID_SOCKET == this->_sock) {
			printf("建立socket=<%d>连接。\n", this->_sock);
			this->initSocket();
		}

		// 2. connect server
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET; // IPv4
		_sin.sin_port = htons(port); // Port

#ifdef _WIN32
		_sin.sin_addr.S_un.S_addr = inet_addr(ip); // IP
#else
		_sin.sin_addr.s_addr = inet_addr(ip); // IP
#endif

		int ret = connect(this->_sock, (struct sockaddr *)&_sin, sizeof(sockaddr_in));
		if (SOCKET_ERROR == ret) {
			printf("socket=<%d>连接服务器<%s:%d>失败。\n", this->_sock, ip, port);
			return ERROR_CODE;
		}
		else {
			printf("socket=<%d>连接服务器socket=<%s:%d>成功。\n", this->_sock, ip, port);
		}
}
	/**
	 * 关闭socket
	 */
	void close() {

		if (INVALID_SOCKET != this->_sock) {
#ifdef _WIN32
			// 关闭Win Sock 2.x环境
			closesocket(this->_sock);
			// clean Windows socket Env
			WSACleanup();
#else
			close(this->_sock);
#endif
			this->_sock = INVALID_SOCKET;
		}
	}

	/**
	 * 处理网络消息
	 */
	bool onRun() {
		if (isRun()) {
			fd_set fdReads;
			FD_ZERO(&fdReads);
			FD_SET(this->_sock, &fdReads);
			timeval t = { 1, 0 };
			int ret = select(this->_sock + 1, &fdReads, 0, 0, &t);
			if (ret < 0) {
				printf("<socket=%d>select任务结束1\n", this->_sock);
				this->close();
				return false;
			}
			if (FD_ISSET(this->_sock, &fdReads)) {
				FD_CLR(this->_sock, &fdReads);
				if (-1 == this->recvData(this->_sock)) {
					printf("<socket=%d>select任务结束2\n", this->_sock);
					this->close();
					return false;
				}
			}
			return true;
		}
		return false;
	}

	/**
	 * 接受数据:处理粘包
	 */
	int recvData(SOCKET _cSock) {
		// 缓冲区
		char recvMsg[1024] = "";
		int nLen = (int)recv(_cSock, (char *)&recvMsg, sizeof(DataHeader), 0);
		DataHeader* header = (DataHeader*)recvMsg;

		if (nLen <= 0) {
			printf("与服务器socket=<%d>断开连接，任务结束\n", this->_sock);
			return -1;
		}

		recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		this->onNetMsg(header);
		return 0;
	};

	/**
	 * 发送数据
	 */
	int sendData(DataHeader* header) {
		if(isRun() && header) {
			printf("dataLenth=%d\n", header->dataLength);
			return send(this->_sock, (const char*)header, header->dataLength, 0);
		}
		return SOCKET_ERROR;
	};

	/**
	 * 相应网络消息
	 */
	void onNetMsg(DataHeader* header) {
		switch (header->cmd) {
			case CMD_LOGIN_RESULT: {
				LoginResult* loginResult = (LoginResult *)header;
				printf("socket=<%d>收到服务器消息: CMD_LOGIN_RESULT 数据长度: %d\n", this->_sock, loginResult->dataLength);
			}
			break;

			case CMD_LOGOUT_RESULT: {
				LogoutResult* logoutResult = (LogoutResult *)header;
				printf("socket=<%d>收到服务器消息: CMD_LOGOUT_RESULT  数据长度: %d\n", this->_sock, logoutResult->dataLength);
			}break;

			case CMD_NEW_USER_JOIN: {
				NewUserJoin* newUserJoin = (NewUserJoin *)header;
				printf("socket=<%d>收到服务器消息: CMD_NEW_USER_JOIN  数据长度: %d\n", this->_sock, newUserJoin->dataLength);
			}
			break;
		}
	}


	/**
	 * 是否在运行总
	 */
	bool isRun() {
		return this->_sock != INVALID_SOCKET;
	}
};

#endif







