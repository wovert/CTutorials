
#include <iostream>

using std::cout;


enum class SCHOOL : char {
	wudang,
	emei,
	kuihua,
	tangmen,
	mojiao
};

struct Equip {
	unsigned char lv{ 0 };
	unsigned char ev{ 0 };
};

struct RoleState {
	int value{ 1000 };
	unsigned  MaxValule{ 1000 };
};

struct Role {
	unsigned char lv{ 1 };
	SCHOOL school{ SCHOOL::tangmen };
	Equip weapon{ 1, 1 };
	Equip army{ 1, 10 };
	Equip neck{ 1, 1 };
	long long exp;

	RoleState HP{ 1000, 1000 };
	RoleState MP{ 1000, 1000 };
	RoleState BP{ 1000, 1000 };

	unsigned x{ 500 };
	unsigned y{ 500 };
	unsigned Money{ 1000 };
	unsigned diamond{ 100 };
	unsigned char luck{ 2 };
	unsigned vip_exp;


	unsigned char weaponLv{};
	unsigned char weaponEv{};

	unsigned char armLv{};
	unsigned char armEv{};
};

void game() {
	Role user;
	cout << "生命" << user.HP.value << "/" << user.HP.MaxValule << (char)10;
	cout << "内力" << user.MP.value << "/" << user.MP.MaxValule << (char)10;
	cout << "坐标[" << user.x << "] [" << user.y << "]" << (char)10;

	user.school = SCHOOL::tangmen;
}

int main()
{
	struct CAR {
		char logo { 'A' };
		unsigned short wheel{ 19 };
		unsigned price{ 90000 };
	};

	CAR carA{ 'A', 25, 5000000 };
	CAR carB{ 'B', 20, 8000000 };
	CAR carC{ 'C', 22, 7000000};

	cout << "车品牌=" << carA.logo << "，轮子=" << carA.wheel << "，价格=" << carA.price << (char)10;
	cout << "车品牌=" << carB.logo << "，轮子=" << carB.wheel << "，价格=" << carB.price << (char)10;
	cout << "车品牌=" << carC.logo << "，轮子=" << carC.wheel << "，价格=" << carC.price << (char)10;

	game();
}
