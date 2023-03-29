#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(1);
	v.push_back(3);

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	return 0;
}