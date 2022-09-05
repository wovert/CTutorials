#include <iostream>
#include <string>

using namespace std;

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

class Room {

    // goodGayVisit function can access Class Room general object's private property
    friend void goodGayVisit(Room &room);

    
    // visit2 of GoodGay Class accessClass Room general object's private property
    friend void GoodGay::visit2(Room &room);

    // GoodGay2 Class accessClass Room general object's private property
    friend class GoodGay2;

    private:
        string bedRoom;
    public:
        string livingRoom;
    
    public:
        Room() {
            this->bedRoom = "bedRoom";
            this->livingRoom = "livingRoom";
        }
};

void GoodGay::visit1(Room &room) {
    cout << "GoodGay::visit1 >>> livingRoom=" << room.livingRoom << endl;

    // erorr: Not can acccess private member property
    // cout << Room.beadRoom= << room.bedRoom << endl;
}

void GoodGay::visit2(Room &room) {
    cout << "GoodGay::visit2 >>> livingRoom=" << room.livingRoom << endl;

    cout << "GoodGay::visit2 >>>> bedRoome=" << room.bedRoom << endl;
}

void GoodGay2::visit1(Room &room) {
    cout << "GoodGay2::visit1 >>> livingRoom=" << room.livingRoom << endl;
    cout << "GoodGay2::visit1 >>> bedRoom=" << room.bedRoom << endl;
}

void GoodGay2::visit2(Room &room) {
    cout << "GoodGay2::visit2 >>> livingRoom=" << room.livingRoom << endl;
    cout << "GoodGay2::visit2 >>> bedRoom=" << room.bedRoom << endl;
}

void goodGayVisit(Room &room) {
    cout << "goodGayVisit >>> livingRoom=" << room.livingRoom << endl;
    cout << "goodGayVisit >>> bedRoom=" << room.bedRoom << endl;
}

void test01() {
    Room myRoom;
    goodGayVisit(myRoom);
}

void test02() {
    Room myRoom;
    GoodGay gg;
    gg.visit1(myRoom);
    gg.visit2(myRoom);
}

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