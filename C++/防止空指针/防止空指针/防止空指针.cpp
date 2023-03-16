#include <iostream>

using namespace std;

class Maker {
public:
	void func() {
		if (this == NULL) {
			cout << "this == NULL" << endl;
			return;
		}
		cout << this->a << endl;
	};
private:
	int a;
};

int main()
{

	Maker *m;
	m = NULL;
	m->func();

	return 0;
}