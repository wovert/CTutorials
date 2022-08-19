#include <iostream>
#include <string>

using namespace std;

// Room向前声明, 说明Room 这个类存在，但不能描述Room有哪些成员
class Room;

class GoodGay {
    public:
        void visit1(Room &room);
        void visit2(Room &room); 
};

class GoodGay2 {
    public:
        void visit1(Room &room);
        void visit2(Room &room); 
};

// 房间类
class Room {
    // 将goodGayVisit作为类的友元函数，即goodGayVisit访问类中的所有属性，但不是类的成员
    friend void goodGayVisit(Room &room);

    
    // visit2作为Room类的友元， visit2就可以访问room的私有数据
    friend void GoodGay::visit2(Room &room);

    // GooGay2的所有成员函数 都可以访问 Room私有数据
    friend class GoodGay2;

    private:
        string bedRoom; // 卧室
    public:
        string livingRoom; // 客厅
    
    public:
        Room() {
            this->bedRoom = "卧室";
            this->livingRoom = "客厅";
        }
};

void GoodGay::visit1(Room &room) {
    cout << "好基友访问你的visit1" << room.livingRoom << endl;

    // 不能访问私有属性
    // cout << "好基友访问你的" << room.bedRoom << endl;
}

void GoodGay::visit2(Room &room) {
    cout << "好基友访问你的visit2" << room.livingRoom << endl;

    // 不能访问私有属性
    cout << "好基友访问你的visit2" << room.bedRoom << endl;
}

void GoodGay2::visit1(Room &room) {
    cout << "好基友GoodGay2访问你的visit1" << room.livingRoom << endl;
    cout << "好基友GoodGay2访问你的visit1" << room.bedRoom << endl;
}

void GoodGay2::visit2(Room &room) {
    cout << "好基友GoodGay2访问你的visit2" << room.livingRoom << endl;
    cout << "好基友GoodGay2访问你的visit2" << room.bedRoom << endl;
}

// 普通全局函数作为类的友元
// 好基友访问我的房间
void goodGayVisit(Room &room) {
    cout << "好基友访问你的" << room.livingRoom << endl;
    cout << "好基友访问你的" << room.bedRoom << endl;
}

void test01() {
    Room myRoom;
    goodGayVisit(myRoom);
}

// 类的某个成员函数作为另一个类的友元
void test02() {
    Room myRoom;
    GoodGay gg;
    gg.visit1(myRoom);
    gg.visit2(myRoom);
}

// 一个类的所有成员函数 访问 另一个类的私有数据
void test03() {
    Room myRoom;
    GoodGay2 gg;
    gg.visit1(myRoom);
    gg.visit2(myRoom);
}

int main() {
    // test01();
    // test02();
    test03();
    return 0;
}