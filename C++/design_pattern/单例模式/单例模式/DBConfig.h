#pragma once

#include <string>
#include <mutex>

class DBConfig
{
public:
	static volatile DBConfig* config;
	static std::mutex mut;
	static volatile DBConfig* getInstance();

	DBConfig();
	std::string getConn();
	std::string getUsername();
	std::string getPassword();
private:
	std::string conn;
	std::string username;
	std::string password;
};

