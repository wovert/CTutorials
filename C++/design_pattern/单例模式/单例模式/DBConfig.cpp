#include <fstream>
#include <iostream>
#include <thread>

#include "DBConfig.h";

volatile DBConfig* DBConfig::config = nullptr;
std::mutex DBConfig::mut;

volatile DBConfig* DBConfig::getInstance()
{
	if (config == nullptr) {
		mut.lock();
		if (config == nullptr) {
			config = new DBConfig();
		}
		mut.unlock();
	}
	return config;
}

DBConfig::DBConfig()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	// Read Config
	std::fstream fs("config.txt");
	char tempStr[1024];
	int index = 0;
	while (fs.getline(tempStr, 1024)) {
		if (index == 0) {
			conn = tempStr;
		}
		else if (index == 1) {
			username = tempStr;
		}
		else if (index == 2) {
			password = tempStr;
		}
		index++;
	}

	printf("Read config from file\n");
}

std::string DBConfig::getConn()
{
	return conn;
}

std::string DBConfig::getUsername()
{
	return username;
}

std::string DBConfig::getPassword()
{
	return password;
}