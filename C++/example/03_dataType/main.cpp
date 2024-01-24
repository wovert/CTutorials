
#include <iostream>

#include <locale>

#define 整数 int
#define 长整型 long

int main()
{
    setlocale(LC_ALL, "chs");

    //unsigned short salary; // 工资 0-65535
    //unsigned short jiangjin; // 奖金 0-65535
    //unsigned short total; // 总数 
    //
    //std::cout << "请输入您的工资：";
    //std::cin >> salary;
    //std::cout << "请输入您的奖金：";
    //std::cin >> jiangjin;

    //std::cout << "您的工资：" << salary << std::endl;
    //std::cout << "您的奖金是：" << jiangjin << std::endl;
    //std::cout << "总数：" << (salary + jiangjin) << std::endl;

    //char charA{ 65 };
    //char charB{ 'B' };
    //char charC{ charB + 1 };
    //std::cout << "A=" << charA << std::endl;
    //std::cout << "B=" << (int)charB << std::endl;
    //std::cout << "c=" << charC << std::endl;

    //// 2 or 4
    //wchar_t cn{ L'中' };
    //std::cout << cn << std::endl;
    //std::wcout << cn << std::endl;

    //// utf-16
    //char16_t char16{ u'a' };
    //char32_t char32{ U'b' };

    //std::cout << char16 << ", " << sizeof(char16) << char(10);
    //std::wcout << char32 << ", " << sizeof(char32) << std::endl;

    //std::cout << "0=" << char(48) << std::endl;
    //std::cout << "9=" << char(57) << std::endl;
    //std::cout << "A=" << char(65) << std::endl;
    //std::cout << "a=" << char(97) << std::endl;

    
    //char inputC;
    //std::wcout << L"请输入一个小写字母:";
    //std::cin >> inputC;
    //inputC -= 32;
    //std::wcout << L"小写字母转换为大写：" << inputC << std::endl;


    // 推断类型
    //auto myAge{ 20 };
    //auto mySalary{ 100000LL };
    //auto myMoney{ 100000L };
    //auto cChar{ U'A' }; // U => char32_t
    //auto bChar{ u'A' }; // L => char16_t
    //auto eChar { L'A'}; // L => wchar_t

    //// int
    //std::wcout << "My Age is " << myAge << std::endl;
    //// long
    //std::wcout << "My Money type is " << typeid(myMoney).name() << std::endl;
    //// __int64
    //std::wcout << "My Salary type is " << typeid(mySalary).name() << std::endl;
    //// char32_t
    //std::wcout << "My cChar type is " << typeid(cChar).name() << std::endl;
    //// char16_t
    //std::wcout << "My Chbar type is " << typeid(bChar).name() << std::endl;
    //// wchar_t
    //std::wcout << "My eChar type is " << typeid(eChar).name() << std::endl;

    // 枚举类型
    // 默认是int类型，且只能是整数类型
    // 枚举类型和其他类型转换需要强制转换
    // 默认情况下，枚举类型的下一个选项初始值是上一个项的初始值+1
    //enum class EquipLv :short {
    //    normal=10,  armyA = normal,
    //    high,       armyB = high,
    //    rate,       armyC = rate,
    //    epic,       armyD = epic,
    //    legend,     armyE = legend,
    //    myth=100,   armyF = myth,
    //};

    //EquipLv weaponCLv { EquipLv::normal };
    //EquipLv weaponDLv { EquipLv::myth };

    //short diff = (int)weaponDLv - (int)weaponCLv;
    //std::wcout << L"这两件装备的等级差" << diff << std::endl;

    char c_1 = 200;
    /*
     128 64 32 16 8 4 2 1
     128 + 64 = 192 + 8
     1 1 0 0 1 0 0 0
     ----------------
     - 64 + 8 = -72
     1011 0111
  +1 1011 1000
     ----------------
    -0011 1000 = 32 + 16 + 8 = -56 
    */
    printf("c_1=%d\n", c_1);

    unsigned char c_2 = 280;
    /*
     256 128 64 32 16 8 4 2 1
     280 - 256 = 24 = 16 + 8
     1 0001 1000 = 280
       16 + 8 = 24
    */
    printf("c_2=%d\n", c_2);

    
    // 自定义变量
    /*
      #define name datatype
    */
    整数 a{ 100 };
    std::cout << typeid(a).name() << char(10); 

    typedef int integer;
    integer b{};
    std::cout << typeid(b).name() << char(10); 

    using int32 = int;
    std::cout << typeid(int32).name() << char(10);

    typedef 长整型 long int64;
    std::cout << typeid(int64).name() << char(10);

    using integer64 = long long;
    std::cout << typeid(integer64).name() << char(10);

    using number64 = 长整型 long;
    std::cout << typeid(number64).name() << char(10);

    system("pause");
    
}

