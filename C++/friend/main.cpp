#include <iostream>
#include <string>

using namespace std;

// Room��ǰ����, ˵��Room �������ڣ�����������Room����Щ��Ա
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

// ������
class Room {
    // ��goodGayVisit��Ϊ�����Ԫ��������goodGayVisit�������е��������ԣ���������ĳ�Ա
    friend void goodGayVisit(Room &room);

    
    // visit2��ΪRoom�����Ԫ�� visit2�Ϳ��Է���room��˽������
    friend void GoodGay::visit2(Room &room);

    // GooGay2�����г�Ա���� �����Է��� Room˽������
    friend class GoodGay2;

    private:
        string bedRoom; // ����
    public:
        string livingRoom; // ����
    
    public:
        Room() {
            this->bedRoom = "����";
            this->livingRoom = "����";
        }
};

void GoodGay::visit1(Room &room) {
    cout << "�û��ѷ������visit1" << room.livingRoom << endl;

    // ���ܷ���˽������
    // cout << "�û��ѷ������" << room.bedRoom << endl;
}

void GoodGay::visit2(Room &room) {
    cout << "�û��ѷ������visit2" << room.livingRoom << endl;

    // ���ܷ���˽������
    cout << "�û��ѷ������visit2" << room.bedRoom << endl;
}

void GoodGay2::visit1(Room &room) {
    cout << "�û���GoodGay2�������visit1" << room.livingRoom << endl;
    cout << "�û���GoodGay2�������visit1" << room.bedRoom << endl;
}

void GoodGay2::visit2(Room &room) {
    cout << "�û���GoodGay2�������visit2" << room.livingRoom << endl;
    cout << "�û���GoodGay2�������visit2" << room.bedRoom << endl;
}

// ��ͨȫ�ֺ�����Ϊ�����Ԫ
// �û��ѷ����ҵķ���
void goodGayVisit(Room &room) {
    cout << "�û��ѷ������" << room.livingRoom << endl;
    cout << "�û��ѷ������" << room.bedRoom << endl;
}

void test01() {
    Room myRoom;
    goodGayVisit(myRoom);
}

// ���ĳ����Ա������Ϊ��һ�������Ԫ
void test02() {
    Room myRoom;
    GoodGay gg;
    gg.visit1(myRoom);
    gg.visit2(myRoom);
}

// һ��������г�Ա���� ���� ��һ�����˽������
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