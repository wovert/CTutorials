#include <iostream>
#include <fstream>
#include <chrono>

#include "DBConfig.h"
#include <thread>

using namespace std;

class Single {
private:
	Single() {
		cout << "Single 构造函数" << endl;
	}
	Single(const Single &s) {
		cout << "Single 拷贝函数" << endl;
	
	}
public:
	~Single() {
		cout << "Single 析构函数" << endl;
	}
public:
	// 静态成员指针
	static Single *single;

	int a;

	// 静态成员函数
	static Single *getSingle() {
		return single;
	}
};

// 类外初始化静态成员变量
// new 在 Single:: 作用域，编译器这时把它当成在类内
// 写法在类外
Single *Single::single = new Single();

// 报错 下面代码执行时，还没有分配空间，所以不能赋值
//int Single::a = 20;

long long getTime()
{
	std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp
		= std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	auto temp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());

	return (long long)temp.count();
}

class SqlQuery {
public:
	SqlQuery(const string &conn, const string &username, const string &password) {
		//cout << "SqlQuery 构造函数" << endl;
		m_conn = conn;
		m_username = username;
		m_password = password;
	}
	SqlQuery(const SqlQuery &s) {
		//cout << "SqlQuery 拷贝函数" << endl;
	}
public:
	~SqlQuery() {
		//cout << "SqlQuery 析构函数" << endl;
	}
	int query() {
		//cout << "SQL 查询操作" << endl;
		return 0;
	}
private:
	string m_conn;
	string m_username;
	string m_password;
public:
	static SqlQuery *sqlQuery;
	static SqlQuery *getSqlQuyery() {
		return sqlQuery;
	}
};


void func()
{
	for (int i = 0; i < 100; i++) {
		//long long startTime = getTime();
		DBConfig::getInstance();
		//long long endTime = getTime();
		//printf("Time:%lld\n", endTime - startTime);
		printf("Query:%d\n", i);
	}
}
void singleTest() {
	Single *single1 = Single::getSingle();
	//Single single2 = *single1;
	Single *single3 = Single::getSingle();
	Single *single4 = Single::getSingle();

	delete single1;
}

void sqlQueryTest() {
	std::thread t1(func);
	std::thread t2(func);

	t1.join();
	t2.join();
}


int main()
{	
	sqlQueryTest();
	//singleTest();
	return 0;
}