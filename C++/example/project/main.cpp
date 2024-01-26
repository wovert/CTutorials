
#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>

#define dVersion "v1.3"
#define dUrl "https://wovert.com"

using namespace std;

void prime(int, int);
void governmentProcurement();
void checkPrime();
void attackRouter();
void narcissisticNumber();
void perfectNumber();
void gameUi();
void gameCard();
void gameLogin();
void bankPw();
void bankPwByFor();
void bankPwByWhile();
void gameSkill();
void gameShowLv();
void gameRepeatAttack();
void gameSkillByArray();
void gameSkillByPointer();

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

		int testPass{};
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
	do testPass++; while (testPass != passwd);
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

struct Skill {
	int needMp; // 需要内力
	int addAck; // 攻击消耗
	int cantAck; // 禁止攻击回合
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

void gameSkillByArray() {
//	//Role user{ 3000, 3000, 1000, 1000, 50, 0, 0, false };
//	//Role boss{ 30000, 30000, 1000, 1000, 190, 0, 0, false };
//
//	Role roles[2]{
//		{ 3000, 3000, 1000, 1000, 50, 0, 0, false },
//		{ 30000, 30000, 1000, 1000, 190, 0, 0, false }
//	};
//
//	// 所有技能
//	Skill skills[5]{
//		{30, 50, 0},
//		{0, 20, 1},
//		{30, 50, 0},
//		{30, 50, 0},
//	};
//
//	int inKey{};
//	do {
//		system("cls");
//		std::cout << "技能快捷键：\n";
//		std::cout << "1: 【治愈】消耗100内力 生命恢复最大生命值的10% " << (char)10;
//		std::cout << "2: 【金刚掌】消耗50内力对远程目标造成基础攻击+50点伤害" << (char)10;
//		std::cout << "3: 【麻痹术】消耗50内力禁止目标攻击三个回合" << (char)10;
//		std::cout << "4: 【鹰抓功】10个回合内，对目标造成伤害将恢复伤害量20%的内力伤害量60%的生命 " << (char)10;
//		std::cout << "5: 【绝处逢生】消耗100内力对目标造成基础攻击+已损失血量的伤害" << (char)10;
//		std::cout << "6: 【易筋经】消耗300内力 内力和生命值互换 攻击力提高1000%" << (char)10;
//
//		printf("生命{ %d / %d }   BOSS生命{ %d / %d }\n", roles[0].Hp, roles[0].MaxHp, roles[1].Hp, roles[1].MaxHp);
//		printf("内力{ %d / %d }   攻击力{ %d }\n", roles[0].Mp, roles[0].MaxMp, roles[0].ack);
//
//		printf("请输入技能：");
//		inKey = _getch() - 49;
//
//		roles[0].Mp -= skills[inKey].needMp;
//		roles[1].Hp = roles[1].Hp - skills[inKey].addAck - roles[0].ack;
//
//
//
//	} while (true);
//
//
//	// 一秒循环一次
//	//while (true) {
//	//	for (Role role: roles) {
//
//	//	}
//	//}
//
//	int damage{};
//	short inKey{};
//
//lfight:
//
//
//	printf("生命{ %d / %d }   BOSS生命{ %d / %d }\n", user.Hp, user.MaxHp, boss.Hp, boss.MaxHp);
//	printf("内力{ %d / %d }   攻击力{ %d }\n", user.Mp, user.MaxMp, user.ack);
//
//	printf("请输入技能：");
//	inKey = _getch();
//
//	switch (inKey) {
//	case 49: // 1
//		if (user.Mp > 99) {
//			user.Mp -= 100;
//			user.Hp += user.MaxHp / 10; // 300
//			user.Hp = user.Hp > user.MaxHp ? user.MaxHp : user.Hp;
//		}
//		break;
//	case 50: // 2
//		if (user.Mp >= 50) {
//			user.Mp -= 50;
//			damage = 50 + user.ack;
//		}
//		break;
//	case 51: // 3
//		if (user.Mp >= 50) {
//			user.Mp -= 50;
//			boss.canack = 3;
//		}
//		break;
//	case 52: // 4
//		user.bufcount = 10;
//		break;
//	case 53: // 5
//		if (user.Mp >= 100) {
//			user.Mp -= 100;
//			damage = user.MaxHp - user.Hp + user.ack;
//		}
//		break;
//	case 54: // 6
//		if (user.Mp >= 300 && !(user.cant)) {
//			user.Mp = user.Mp ^ user.Hp;
//			user.Hp = user.Mp ^ user.Hp;
//			user.Mp = user.Mp ^ user.Hp;
//
//			user.MaxMp = user.MaxMp ^ user.MaxHp;
//			user.MaxHp = user.MaxMp ^ user.MaxHp;
//			user.MaxMp = user.MaxMp ^ user.MaxHp;
//
//			user.cant = true;
//			user.ack *= 10;
//		}
//		break;
//	}
//
//	// boss不能攻击
//	if (boss.canack > 0) {
//		boss.canack--;
//	}
//	else {
//		user.Hp -= boss.ack;
//	}
//	//printf("damage=%d\n", damage);
//	boss.Hp -= damage;
//	//printf("boss.Hp=%d\n", boss.Hp);
//
//	if (user.bufcount > 0) {
//		user.bufcount--;
//		user.Hp += damage * 0.6; // 回血
//		user.Mp += damage * 0.2;
//		user.Hp = user.Hp > user.MaxHp ? user.MaxHp : user.Hp;
//		user.Mp = user.Mp > user.MaxMp ? user.MaxMp : user.Mp;
//	}
//
//	if (user.Hp < 1) {
//		system("cls");
//		printf("游戏结束");
//	}
//	else if (boss.Hp < 1) {
//		system("cls");
//		printf("击败boss");
//	}
//	else goto lfight;
}

void gameSkillByPointer() {
	Role user{ 3000, 3000, 1000, 1000, 50, 0, 0, false };
	Role boss{ 30000, 30000, 1000, 1000, 190, 0, 0, false };
	int damage{};
	short inKey{};

	int* pBossHp = &boss.Hp;
	int* pBossMaxHp = &boss.MaxHp;
	int* pBossCanack = &boss.canack;

	int* pUserHp = &user.Hp;
	int* pUserMaxHp = &user.MaxHp;
	int* pUserMp = &user.Mp;
	int* pUserMaxMp = &user.MaxMp;
	int* pUserAck = &user.ack;

lfight:
	system("cls");
	std::cout << "技能快捷键：\n";
	std::cout << "1: 【治愈】消耗100内力 生命恢复最大生命值的10% " << (char)10;
	std::cout << "2: 【金刚掌】消耗50内力对远程目标造成基础攻击+50点伤害" << (char)10;
	std::cout << "3: 【麻痹术】消耗50内力禁止目标攻击三个回合" << (char)10;
	std::cout << "4: 【鹰抓功】10个回合内，对目标造成伤害将恢复伤害量20%的内力伤害量60%的生命 " << (char)10;
	std::cout << "5: 【绝处逢生】消耗100内力对目标造成基础攻击+已损失血量的伤害" << (char)10;
	std::cout << "6: 【易筋经】消耗300内力 内力和生命值互换 攻击力提高1000%" << (char)10;

	printf("生命{ %d / %d }   BOSS生命{ %d / %d }\n", *pUserHp, *pUserMaxHp, *pBossHp, *pBossMaxHp);
	printf("内力{ %d / %d }   攻击力{ %d }\n", *pUserMp, *pUserMaxMp, *pUserAck);

	printf("请输入技能：");
	inKey = _getch();

	switch (inKey) {
	case 49: // 1
		if (*pUserMp > 99) {
			*pUserMp -= 100;
			*pUserHp += *pUserMaxHp / 10; // 300
			*pUserHp = *pUserHp > *pUserMaxHp ? *pUserMaxHp : *pUserHp;
		}
		break;
	case 50: // 2
		if (*pUserMp >= 50) {
			*pUserMp -= 50;
			damage = 50 + *pUserAck;
		}
		break;
	case 51: // 3
		if (*pUserMp >= 50) {
			*pUserMp -= 50;
			*pBossCanack = 3;
		}
		break;
	case 52: // 4
		user.bufcount = 10;
		break;
	case 53: // 5
		if (*pUserMp >= 100) {
			*pUserMp -= 100;
			damage = *pUserMaxHp - *pUserHp + *pUserAck;
		}
		break;
	case 54: // 6
		if (*pUserMp >= 300 && !(user.cant)) {
			*pUserMp = *pUserMp ^ *pUserHp;
			*pUserHp = *pUserMp ^ *pUserHp;
			*pUserMp = *pUserMp ^ *pUserHp;

			*pUserMaxMp = *pUserMaxMp ^ *pUserMaxHp;
			*pUserMaxHp = *pUserMaxMp ^ *pUserMaxHp;
			*pUserMaxMp = *pUserMaxMp ^ *pUserMaxHp;

			user.cant = true;
			*pUserAck *= 10;
		}
		break;
	}

	// boss不能攻击
	if (*pBossCanack > 0) {
		*pBossCanack--;
	}
	else {
		*pUserHp -= boss.ack;
	}
	//printf("damage=%d\n", damage);
	*pBossHp -= damage;
	//printf("*pBossHp=%d\n", *pBossHp);

	if (user.bufcount > 0) {
		user.bufcount--;
		*pUserHp += damage * 0.6; // 回血
		*pUserMp += damage * 0.2;
		*pUserHp = *pUserHp > *pUserMaxHp ? *pUserMaxHp : *pUserHp;
		*pUserMp = *pUserMp > *pUserMaxMp ? *pUserMaxMp : *pUserMp;
	}

	if (*pUserHp < 1) {
		system("cls");
		printf("游戏结束");
	}
	else if (*pBossHp < 1) {
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
	int Mp{ 1383 }, lsMp{ Mp };
	int damage{}, needMp{};

	do {
		damage += 100; // 对目标的伤害累计100
		Mp -= needMp; // 自己消耗50
		needMp += 50; // 累计消耗
		std::cout << "\n 造成伤害" << damage << "剩余MP" << Mp;
	} while (Mp >= needMp);
	Mp = lsMp;
}

// 求指数
void prime(int start = 3, int end = 1000) {
    bool flag{};
    short count{ 0 };
    int num{ 0 };

    // 指数不可能被2整除, 使用奇数
    //for (int i = start; i < end; i++) {
    for (int i = start; i < end; i += 2) {
        flag = false;
        //for (int c = 2; c < i; c++) {
        for (int c = 3; c <= sqrt(i); c += 2) {
            num++;
            if (i % c == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            count++;
            std::cout << std::setfill('0') << std::setw(3) << i << "\t";
            if (count % 10 == 0) std::cout << std::endl;
        }
    }
    std::cout << "\n累计计算量 : " << num << (char)10;
    std::cout << "\ntotal prime : " << count << (char)10;
}

// 政府采购项目
void governmentProcurement() {
    // 1万资金
    // 100件家具
    // 高级桌子每张500元
    // 普通桌子每张300元
    // 椅子三把100元
    int count{ 0 };
    /*
      ax500 + bx300 + cx(100/3) = 10000
      a + b + c = 100
      500 100 => 10000/500 => 20
      300 100 => 10000/300 => 33
    */
    int icount = 10000 / 500;
    int jcount = 10000 / 300;
    for (int i = 1; i <= icount; i++) {
        for (int j = 1; j <= jcount-i; j++) {
            int k = 100 - i - j;
            count++;
            if ((k%3 == 0) && (i * 500 + j * 300 + k * 100 / 3 == 10000)) {
                std::cout << "高级桌子数量: " << i << (char)10;
                std::cout << "普通桌子数量: " << j << (char)10;
                std::cout << "椅子数量: " << k << (char)10;
                std::cout << "-------------" << (char)10;
            }
        }
    }
    // 100 0000
    //  16 2925
    //   6 6000
    //   3 5320
    //      660
    //      392
    std::cout << "运算次数: " << count << (char)10;


    /*
    0 <= i <= 20
    0 <= j <= 33
    100-20-33 => 47 <= k <= 100
    
    ix500 + jx300 + kx(100/3) = 10000
    1500i + 900j + 100k = 30000
    15i + 9j + k = 300
    i + j + k = 100
     
    15i + 9j + 100 - i -j = 300
    14i + 8j + 100 = 300
    14i + 8j = 200
    7i + 4j = 100

    4j = 100-7i
    j = 25 - 7/4i;

    0 <= j <= 33

    0 <= 25 - 7/4i <= 33 
    i必须是4倍数
    i = 4num

    j = 25 - 7/4i
    j = 25-7num

    k=100-4num-25-7num
    k=75+3num

    num = ????????????

    0 <= 4num <= 20
    num <= 5

    0 <= 25-7num <= 33
    -25 <= -7num <= 7
    -25 <= -7num
    25/7 >= num
    3 >= num
    3 >= num <= 5

    0 <= 25-7num <= 33
    -25 <= -7num <= 7
    -25/7 <= -num
    25/7 >= num
    3 >= num
    
    45 <= 75+3num <= 100
    0 <= 30+3num <= 55-30
    -30 <= 3num <= 25
    num <= 25/3 = 7
    num <= 7
    
    */
    for (int num{0}; num <= 3; num++) {
        std::cout << "高级桌子数量: " << num*4 << (char)10;
        std::cout << "普通桌子数量: " << 25-num*7 << (char)10;
        std::cout << "椅子数量: " << 75+3*num << (char)10;
    }

}

void checkPrime() {
    int n{};
    char c{ 'Y' };
    
    do {
        std::cout << "\n请输入数字：";
        std::cin >> n;
        //std::cout << n << (char)10;

        int i = 1;
        bool flag{};
        flag = n % 2 != 0;

        //while (flag && i<=sqrt(n)) {
        //    if (i != 1 && n % i == 0) {
        //        flag = false;
        //        break;
        //    }
        //    i += n > 10 ? 2 : 1;
        //}
        do {
            if (i != 1 && n % i == 0) {
                flag = false;
                break;
            }
            i += n > 10 ? 2 : 1;
        } while (flag && i <= sqrt(n));


        if (flag) {
            std::cout << n << " 是质数." << (char)10;
        }
        else {
            std::cout << n << " 不是质数." << (char)10;
        }

        std::cout << "继续按下[Y]键 按下其他任意键退出程序";
        std::cin >> c;

    } while (c == 'Y' || c == 'y');

    std::cout << "退出程序\n";
}

// wps功能路由器入侵：模拟WPS路由器破解的场景
void attackRouter() {
    int passwd{ 87654321 };
    int crackPass{};
    // goto
//lcrack:
//    if (crackPass != passwd) {
//        crackPass++;
//        goto lcrack;
//    }
//    std::cout << "【goto版本】路由PIN=" << crackPass << (char)10;

    // for
    //for (crackPass = 0; crackPass == passwd; crackPass++);
    //std::cout << "【for版本】路由PIN=" << crackPass << (char)10;

    // while
    //crackPass = 0;
    //while (crackPass != passwd)crackPass++;
    //std::cout << "【while版本】路由PIN=" << crackPass << (char)10;

    // do while
    //crackPass = 0;
    //do crackPass++; while (crackPass != passwd);
    //std::cout << "【do while版本】路由PIN=" << crackPass << (char)10;
}

// 水仙花数：一个三位数立方和等于该数本身
// 153， 1立方，5立方，3立方 = 153 = 1+25*5+27= 125 + 28 = 153
void narcissisticNumber() {
    // 100-1000之间的水仙花数
    for (short i = 100; i < 1000; i++) {
        // 328
        short a = i/100; // 328/100 = 3
        short b = i/10%10;  //(328 - 300) / 10 = 2
        short c = i%10;
        if (a * a * a + b * b * b + c * c * c == i) {
            std::cout << i << "----> a^3=" << a*a*a << ",b^3=" << b*b*b << ", c^3=" << c*c*c << (char)10;
        }

    }
}

// 完数=出去自然是本身以外的一切因数和相等
void perfectNumber() {
    // 1000以内的完数 6=1 2 3
    for (int i = 1; i < 1000; i++) {
        int total{0};
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                total += j;
            }
        }
        if (total == i) {
            std::cout << total << (char)10;
        }
    }
}

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
    //gameRepeatAttack();
    //prime();
    //governmentProcurement();
    //checkPrime();
    //attackRouter();
    //narcissisticNumber();
    //perfectNumber();
	//gameSkillByArray();
	gameSkillByPointer();
}
