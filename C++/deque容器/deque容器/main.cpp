#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;
void demo01() {
	
	deque<int>::iterator it;
	//it++;
	//it--;
	//it + 2;
}
void print(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

// 构造函数
void demo02() {
	int arr[] = {1,25,38,12,8};

	// deque(begin, end);
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(int));
	print(d1);

	// dequen(n, ele)
	deque<int> d2(10, 6);
	print(d2);

	// deque(const deque &d) 拷贝构造函数
	deque<int> d3(d1);
	print(d3);

	deque<int> d4;
	d4.assign(d1.begin(), d1.end());
	d4.push_back(300);
	print(d4);

	cout << "---------" << endl;
	d4.swap(d1);
	cout << "---------" << endl;
	print(d4);
	cout << "---------" << endl;
	print(d1);
}

void demo03() {
	int arr[] = { 1,25,38,12,8 };

	// deque(begin, end);
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(int));
	d1.at(0) = 100;
	d1[3] = 400;
	d1.push_front(239);
	print(d1);

	cout << "d1.size=" << d1.size() << endl;
	d1.pop_back();
	print(d1);

	d1.insert(d1.begin(), 100);
	d1.insert(d1.begin() + 3, 2, 0);
	print(d1);

}

int main() {
	demo03();
	//demo02();
	//demo01();
	return 0;
}