#include <iostream>
#include <fstream>

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


class SqlQuery {
private:
	SqlQuery(const string &conn, const string &username, const string &password) {
		m_conn = conn;
		m_username = username;
		m_password = password;
		cout << "SqlQuery 构造函数" << endl;
	}
	SqlQuery(const SqlQuery &s) {
		cout << "SqlQuery 拷贝函数" << endl;
	}
public:
	~SqlQuery() {
		cout << "SqlQuery 析构函数" << endl;
	}
	int query() {
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


void singleTest() {
	Single *single1 = Single::getSingle();
	//Single single2 = *single1;
	Single *single3 = Single::getSingle();
	Single *single4 = Single::getSingle();

	delete single1;
}

void sqlQueryTest() {
	string conn = "mysql://localhost:3306/test/";
	string username = "root";
	string password = "root";
	
	fstream fs("./config.txt");
	char str[1024];
	int index = 0;
	while (fs.getline(str, 1024)) {
		if (index == 0) {
			conn = str;
		}
		else if (index == 1) {
			username = str;
		}
		else if (index == 2) {
			password = str;
		}
		index++;
	}

	printf("conn:%s\n", conn.c_str());
	printf("username:%s\n", username.c_str());
	printf("password:%s\n", password.c_str());
}


int main()
{	
	sqlQueryTest();
	//singleTest();
	return 0;
}