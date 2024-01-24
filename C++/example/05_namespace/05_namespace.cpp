#include <iostream>

using std::cout; // 优先使用
using std::endl;
//using namespace std;

namespace Game {
	int HP{ 1000 };
	int MP{ 1000 };
	int lv{ 1 };
	namespace GameWeapon {
		int damage{ 3000 };
		namespace WeaponInfo {
			int lv = Game::lv;
		}
	}
}

int main()
{
	cout << "不需要std" << endl;

	using Game::HP;
	cout << HP << endl;

	int c = Game::GameWeapon::damage;
	cout << c << endl;
}
