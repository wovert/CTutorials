#include <iostream>
#include <conio.h>
#include <iomanip>


#define dVersion "v1.3"
#define dUrl "https://wovert.com"

using namespace std;

void gameUi();
void gameCard();
void gameLogin();
void bankPw();
void bankPwByFor();
void bankPwByWhile();
void gameSkill();
void gameShowLv();
void gameRepeatAttack();

int main()
{
	//gameUi();
	//gameCard();
	//gameLogin();
	//bankPw();
	//gameSkill();
	//bankPwByFor();
	//bankPwByWhile();
	//gameShowLv();
	gameRepeatAttack();

}

void gameUi() {
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "             麟江湖\"控制台\"版 " << dVersion << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "             正在加载游戏..." << std::endl;
	std::cout << "             进度【8/100】" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "            官方网站 " << dUrl << std::endl;
	std::cout << "==================================================" << std::endl;
	system("pause");
	system("cls");

	unsigned short birthYear;
	float height;
	unsigned short weight;
	unsigned short gender; // 0:female 1: male
	unsigned long long mobile;
	unsigned long long endInfo;

	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "             麟江湖\"控制台\"版 " << dVersion << std::endl;
	std::cout << "请输入您的出生年:";
	std::cin >> birthYear;

	std::cout << "请输入您的身高:";
	std::cin >> height;

	std::cout << "请输入您的体重:";
	std::cin >> weight;

	std::cout << "请输入您的性别:";
	std::cin >> gender;

	std::cout << "请输入您的手机号:";
	std::cin >> mobile;

	endInfo = (mobile / 2 + birthYear) * 10000000;
	float fls = height * height / weight;
	endInfo += (int)fls;
	endInfo *= 10;
	endInfo += gender;

	std::cout << "您的激活码为：" << endInfo << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "            官方网站 " << dUrl << std::endl;
	std::cout << "==================================================" << std::endl;
	system("pause");
	system("cls");
}

void gameCard() {
	system("color 07");

	unsigned long long m_code{ 930529060092641281ULL }; // 硬件码 0x FFFF FFFF
	unsigned long long test_code{ 0xF2349876EF56CA24ULL }; // 内置一个测试码
	unsigned long long apply_code{};

	//long long end = m_code ^ test_code; // 简单验证算法 fedd 7f36 ef56 ca25 2556 595f f=15
	apply_code = m_code ^ test_code ^ 0x2556595f;

	//std::cout << std::hex << end << (char)10;
	//std::cout << (end ^ test_code) << (char)10;

	unsigned short in_code1, in_code2, in_code3, in_code4, in_code5, in_code6;
	std::cout << "依次输入各组激活码(第一组)：";
	std::cin >> std::hex; // 16进制模式输入
	std::cin >> in_code1;
	std::cout << "依次输入各组激活码(第二组)：";
	std::cin >> in_code2;
	std::cout << "依次输入各组激活码(第三组)：";
	std::cin >> in_code3;
	std::cout << "依次输入各组激活码(第四组)：";
	std::cin >> in_code4;
	std::cout << "依次输入各组激活码(第五组)：";
	std::cin >> in_code5;
	std::cout << "依次输入各组激活码(第六组)：";
	std::cin >> in_code6;

	unsigned long long end{};
	unsigned long long ls{}; // 临时变量

	// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx 
	// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx oooo oooo oooo oooo
	ls = in_code1;
	ls <<= 48;
	end = ls;

	ls = in_code2;
	ls <<= 32;
	end |= ls;

	ls = in_code3;
	ls <<= 16;
	end |= ls;

	end |= in_code4;

	end ^= test_code;

	unsigned gMoney;
	char gluck;

	gMoney = (in_code5 & 0xF000) >> 12;
	gMoney *= gMoney;
	gMoney *= 10000;

	gluck = (in_code5 & 0x0F00) >> 8;

	char weaponlv; // 武器的阶
	char weaponev; // 武器的强化

	char armylv, armyev; // 装备的阶 和 强化
	char necklv, neckev; // 首饰的阶段 和 强化

	weaponlv = (in_code5 & 0x00F0) >> 4;
	weaponev = in_code5 & 0xf;

	armylv = (in_code6 & 0xF000) >> 12;
	armyev = (in_code6 & 0x0F00) >> 8;

	necklv = (in_code6 & 0x00F0) >> 4;
	neckev = in_code6 & 0xf;

	std::cout << "您获得了" << gMoney << "的金币礼包！" << (char)10;
	std::cout << "您的幸运值为" << (short)gluck << "!" << (char)10;
	std::cout << "您获得的强化为" << (short)weaponev << "阶为：" << (short)weaponlv << "的武器" << (char)10;
	std::cout << "您获得的强化为" << (short)armyev << "阶为：" << (short)armylv << "的装备" << (char)10;
	std::cout << "您获得的强化为" << (short)neckev << "阶为：" << (short)necklv << "的首饰" << (char)10;

	std::cout << "可以激活的硬件码为：" << end << (char)10;
	std::cout << "可以激活的硬件码附加码为：" << std::hex << (end ^ test_code ^ apply_code) << (char)10;

	system("pause");
}

void gameLogin() {
	unsigned long long uId, uPass;

	cout << "游戏注册\n\n请输入您的账户（16位十六进制）";
	cin >> std::hex >> uId;
	cout << "\n\n请输入您的密码：";
	cin >> std::hex >> uPass;

	// 注册部分
	if ((uId > 0xFFFFF) && (uPass > 0xFFFFF)) {
		unsigned long long uInId, uInPass;

		system("cls");
		cout << "游戏注册\n\n请输入您的账户（16位十六进制）";
		cin >> uInId;
		cout << "\n\n请输入您的密码：";
		cin >> uInPass;

		if (uId == uInId) {
			if (uPass == uInPass) {
				cout << "登录游戏！";
			}
			else {
				"对不起，您的密码输入错误！";
			}
		}
		else {
			cout << "对不起，您的账户输入错误！";
		}
	}
	else {
		cout << "注册失败！账户或者密码不足5位！";
	}
}

void bankPw() {
	unsigned int passwd, repasswd;

linput:
	system("cls");
	std::cout << "请您输入一个6位数字密码：";
	std::cin >> passwd;
	std::cout << "请您再输入一个6位数字密码：";
	std::cin >> repasswd;

	if (passwd == repasswd) {
		if (passwd > 999999) goto linput;
		system("cls");
		std::cout << "密码设置成功!\n按下任意键进入破解系统";
		_getch(); // 等待输入任意键

		int testPass {} ;
lhack:
		if (testPass != passwd) {
			testPass++;
			goto lhack;
		}
		else {
		std::cout << "密码破解成功！" << testPass << (char)10;
		}
	}
	else goto linput;
}

void bankPwByFor() {
	unsigned int passwd{ 1 }, repasswd{};
	
	for (; passwd != repasswd;) {
		if (passwd > 999999) continue;
		system("cls");
		std::cout << "请您输入一个6位数字密码：";
		std::cin >> passwd;
		std::cout << "请您再输入一个6位数字密码：";
		std::cin >> repasswd;
	}
	
	system("cls");
	std::cout << "密码设置成功!\n按下任意键进入破解系统";
	_getch(); // 等待输入任意键

	int testPass{};

	for (; testPass != passwd; testPass++);
	std::cout << "密码破解成功！" << testPass << (char)10;

}

void bankPwByWhile() {
	unsigned int passwd{ 1 }, repasswd{};

	do {
		std::cout << "请您输入一个6位数字密码：";
		std::cin >> passwd;
		std::cout << "请您再输入一个6位数字密码：";
		std::cin >> repasswd;
	} while (passwd != repasswd || passwd > 999999);


	system("cls");
	std::cout << "密码设置成功!\n按下任意键进入破解系统";
	_getch(); // 等待输入任意键

	int testPass{};

	//while (testPass != passwd) testPass++;
	do testPass++; while(testPass != passwd);
	std::cout << "密码破解成功！" << testPass << (char)10;

}


struct Role {
	int Hp;
	int MaxHp; // 最高生命 3000
	int Mp;
	int MaxMp; // 最高内力值 1000
	int ack; // 基础攻击力
	int canack; // 禁止攻击回合
	int bufcount; // 回合
	bool cant;				// 易筋经状态
};

void gameSkill() {
	Role user{ 3000, 3000, 1000, 1000, 50, 0, 0, false };
	Role boss{ 30000, 30000, 1000, 1000, 190, 0, 0, false };
	int damage{};
	short inKey{};

lfight:
	system("cls");
	std::cout << "技能快捷键：\n";
	std::cout << "1: 【治愈】消耗100内力 生命恢复最大生命值的10% " << (char)10;
	std::cout << "2: 【金刚掌】消耗50内力对远程目标造成基础攻击+50点伤害" << (char)10;
	std::cout << "3: 【麻痹术】消耗50内力禁止目标攻击三个回合" << (char)10;
	std::cout << "4: 【鹰抓功】10个回合内，对目标造成伤害将恢复伤害量20%的内力伤害量60%的生命 " << (char)10;
	std::cout << "5: 【绝处逢生】消耗100内力对目标造成基础攻击+已损失血量的伤害" << (char)10;
	std::cout << "6: 【易筋经】消耗300内力 内力和生命值互换 攻击力提高1000%" << (char)10;

	printf("生命{ %d / %d }   BOSS生命{ %d / %d }\n", user.Hp, user.MaxHp, boss.Hp, boss.MaxHp);
	printf("内力{ %d / %d }   攻击力{ %d }\n", user.Mp, user.MaxMp, user.ack);

	printf("请输入技能：");
	inKey = _getch();

	switch (inKey) {
	case 49: // 1
		if (user.Mp > 99) {
			user.Mp -= 100;
			user.Hp += user.MaxHp / 10; // 300
			user.Hp = user.Hp > user.MaxHp ? user.MaxHp : user.Hp;
		}
		break;
	case 50: // 2
		if (user.Mp >= 50) {
			user.Mp -= 50;
			damage = 50 + user.ack;
		}
		break;
	case 51: // 3
		if (user.Mp >= 50) {
			user.Mp -= 50;
			boss.canack = 3;
		}
		break;
	case 52: // 4
		user.bufcount = 10;
		break;
	case 53: // 5
		if (user.Mp >= 100) {
			user.Mp -= 100;
			damage = user.MaxHp - user.Hp + user.ack;
		}
		break;
	case 54: // 6
		if (user.Mp >= 300 && !(user.cant)) {
			user.Mp = user.Mp ^ user.Hp;
			user.Hp = user.Mp ^ user.Hp;
			user.Mp = user.Mp ^ user.Hp;

			user.MaxMp = user.MaxMp ^ user.MaxHp;
			user.MaxHp = user.MaxMp ^ user.MaxHp;
			user.MaxMp = user.MaxMp ^ user.MaxHp;

			user.cant = true;
			user.ack *= 10;
		}
		break;
	}

	// boss不能攻击
	if (boss.canack > 0) {
		boss.canack--;
	}
	else {
		user.Hp -= boss.ack;
	}
	//printf("damage=%d\n", damage);
	boss.Hp -= damage;
	//printf("boss.Hp=%d\n", boss.Hp);

	if (user.bufcount > 0) {
		user.bufcount--;
		user.Hp += damage * 0.6; // 回血
		user.Mp += damage * 0.2;
		user.Hp = user.Hp > user.MaxHp ? user.MaxHp : user.Hp;
		user.Mp = user.Mp > user.MaxMp ? user.MaxMp : user.Mp;
	}

	if (user.Hp < 1) {
		system("cls");
		printf("游戏结束");
	}
	else if (boss.Hp < 1) {
		system("cls");
		printf("击败boss");
	}
	else goto lfight;
}

void gameShowLv() {
	char cIn = _getch();
	if (cIn == 'l' || cIn == 'L') {
		for (int lv{ 1 }; lv <= 100; lv++) {
			std::cout << std::setfill(' ');
			std::cout << "\n等级" << std::setw(3) << lv << "    所需经验" << std::setw(10) << lv * lv * 100;
		}
	}
}

void gameRepeatAttack() {
	int Mp{ 1383 }, lsMp{Mp};
	int damage{}, needMp{};

	do {
		damage += 100; // 对目标的伤害累计100
		Mp -= needMp; // 自己消耗50
		needMp += 50; // 累计消耗
		std::cout << "\n 造成伤害" << damage << "剩余MP" << Mp;
	} while (Mp >= needMp);
	Mp = lsMp;
}