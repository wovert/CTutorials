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
#include <vector>
#include "MessageHeader.hpp"

using namespace std;

class MiniTCPServer {
private:
	SOCKET _sock;
	std::vector<SOCKET> g_clients;
public:
	MiniTCPServer() {
		_sock = INVALID_SOCKET;
	}

	virtual ~MiniTCPServer() {
		this->close();
	}

	/**
	 * 初始化socket
	 */
	SOCKET initSocket() {

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
		}
		else {
			printf("建立socket成功。\n");
		}
		return this->_sock;
	}
	/**
	 * 绑定端口
	 */
	int bindIpPort(const char* ip, const unsigned short port) {
		if (INVALID_SOCKET == this->_sock) {
			this->initSocket();
			printf("建立socket=<%d>连接。\n", this->_sock);
		}

		// 2. bind socket
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port); // host to net unsgined short
#ifdef _WIN32
		_sin.sin_addr.S_un.S_addr = ip ? inet_addr(ip) : INADDR_ANY;
#else
		_sin.sin_addr.s_addr = ip ? inet_addr(ip) : INADDR_ANY;
#endif

		int ret = bind(this->_sock, (sockaddr *)&_sin, sizeof(_sin));
		if (SOCKET_ERROR == ret) {
			printf("绑定端口<%d>失败\n", port);
		}
		else {
			printf("绑定端口<%d>成功\n", port);
		}
		return ret;
	}
	/**
	 * 监听端口
	 */
	int listenPort(const int n) {
		// 3. listen port
		int ret = listen(this->_sock, n);
		if (SOCKET_ERROR == ret) {
			printf("监听socket=<%d>端口失败\n", _sock);
		}
		else {
			printf("监听socket=<%d>端口<%d>成功\n", _sock);
		}
		return ret;
	}

	/**
	 * 关闭socket
	 */
	void close() {

		if (INVALID_SOCKET != this->_sock) {
#ifdef _WIN32
			for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
				closesocket(g_clients[n]);
			}
			// 关闭Win Sock 2.x环境
			closesocket(this->_sock);
			// clean Windows socket Env
			WSACleanup();
#else
			for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
				close(g_clients[n]);
			}
			close(this->_sock);
#endif
			this->_sock = INVALID_SOCKET;
		}
	}

	SOCKET acceptSocket() {
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
			printf("接收到无效客户端socket<%d>\n", (int)_sock);
		}
		else {
			// 广播
			NewUserJoin userJoin;
			sendDataAll(&userJoin);

			g_clients.push_back(_cSock);
			printf("新的客户端连接 socket=%d, IP:%s\n", (int)_cSock, inet_ntoa(clientAddr.sin_addr));
		}

		return _sock;
	}

	/**
	 * 处理网络消息
	 */
	int _mCount = 1;
	bool onRun() {
		if (isRun()) {
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
			for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
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
			//printf("select ret=%d count=%d\n", ret, _mCount++);
			if (ret < 0) {
				printf("select任务结束\n");
				this->close();
				return false;
			}
			//printf("空闲时间处理其他业务...\n");

			// 判断描述符（socket）是否在集合中
			if (FD_ISSET(_sock, &readFd)) {
				FD_CLR(_sock, &readFd); // 在集合中清空描述符（socket）

				this->acceptSocket();
			}

			for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
				if (FD_ISSET(g_clients[n], &readFd)) {
					if (-1 == recvData(g_clients[n])) {
						// 自动推导类型
						auto iter = g_clients.begin() + n; //std::vector<SOCKET>::iterator iter = g_clients.begin() + n;
						if (iter != g_clients.end()) {
							g_clients.erase(iter);
						}
					}
				}
			}
			return true;
		}
		return false;
	}

	// 第2缓冲区
	char recvMsg[409600] = ""; // 双缓冲

	/**
	 * 接受数据:处理粘包 拆分包
	 */
	int recvData(SOCKET _cSock) {

		//int nLen = (int)recv(_cSock, (char *)&recvMsg, sizeof(DataHeader), 0);
		int nLen = (int)recv(_cSock, (char *)&recvMsg, 409600, 0);
		//printf("nLen=%d\n", nLen);

		LoginResult ret;
		sendData(_cSock, &ret);
		//DataHeader* header = (DataHeader*)recvMsg;

		//if (nLen <= 0) {
		//	printf("客户端<Socket=%d>已退出，任务结束\n", _cSock);
		//	return -1;
		//}

		//recv(_cSock, recvMsg + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);
		//this->onNetMsg(_cSock, header);

		return 0;
	}

	/**
	 * 相应网络消息
	 */
	void onNetMsg(SOCKET _cSock, DataHeader* header) {

		switch (header->cmd) {
		case CMD_LOGIN: {
			Login* login = (Login *)header;
			printf("收到<Socket=%d>命令: CMD_LOGIN 数据长度: %d, username=%s, passwod=%s\n", _cSock,
				login->dataLength, login->username, login->password);

			LoginResult ret;
			sendData(_cSock, &ret);
		}
						break;
		case CMD_LOGOUT: {
			Logout* logout = (Logout *)header;
			printf("收到<Socket=%d>命令: CMD_LOGOUT 数据长度: %d, username=%s\n", _cSock,
				logout->dataLength, logout->username);

			LogoutResult ret;
			sendData(_cSock, &ret);
		}
						 break;
		default:
			DataHeader header = { CMD_ERROR, 0 };
			sendData(_cSock, &header);
		}
	}



	/**
	 * 发送指定Socket数据
	 */
	int sendData(SOCKET _cSock, DataHeader* header) {
		if (isRun() && header) {
			return send(_cSock, (const char*)header, header->dataLength, 0);
		}
		return SOCKET_ERROR;
	}

	/**
	 * 发送给所有在线用户数据
	 */
	void sendDataAll(DataHeader* header) {
		for (int n = (int)g_clients.size() - 1; n >= 0; n--) {
			this->sendData(g_clients[n], header);
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