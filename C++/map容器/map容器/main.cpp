#include <iostream>
#include <map>
#include <string>

using namespace std;



template<class T>
void print(T &m) {
	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}



void test01() {
	map<int, string> m;
	m.insert(pair<int, string>(3, "aaa"));
	m.insert(make_pair(6, "bbb"));
	m.insert(map<int, string>::value_type(2, "ccc"));
	m[4] = "ddd";

	print(m);
}

// 改变规则
struct myMap {
	bool operator()(int k1, int k2) const {
		return k1 > k2;
	}
};

template<class T>
void print2(T &m) {
	for (map<int, string, myMap>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

void test02() {
	map<int, string, myMap> m;
	m.insert(pair<int, string>(3, "aaa"));
	m.insert(make_pair(6, "bbb"));
	m.insert(map<int, string>::value_type(2, "ccc"));
	m[4] = "ddd";

	print2(m);

	cout << "size:" << m.size() << endl;
	// 没有实值，那么键值也存在 返回实值
	cout << m[100] << endl;
	cout << "size:" << m.size() << endl;
	print2(m);
}

void test03() {
	map<int, string, myMap> m;
	m.insert(pair<int, string>(3, "aaa"));
	m.insert(make_pair(6, "bbb"));
	m.insert(map<int, string>::value_type(2, "ccc"));
	m[4] = "ddd";

	print2(m);

	map<int, string>::iterator it = m.find(6);
	if (it == m.end()) {
		cout << "not find" << endl;
	}
	else {
		cout << "find success" << it->first << " value=" << it->second << endl;

	}
}


int main() {
	test03();
	//test02();
	//test01();
	return 0;
}
