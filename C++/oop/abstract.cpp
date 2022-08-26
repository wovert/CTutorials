#include <iostream>
using namespace std;

// 抽象层
// 有纯虚函数类叫做抽象层
class Rule {
public:
    // 纯虚函数
    virtual int getNum(int a, int b) = 0;
};

// 实现层
class RuleAdd :public Rule {
public:
    virtual int getNum(int a, int b) {
        return a + b;
    }
};

// 实现层
class RuleSub :public Rule {
public:
    // 依赖抽象层
    virtual int getNum(int a, int b) {
        return a - b;
    }
};

// 业务层
int doLogin(Rule *r) {
    int a = 10;
    int b = 20;
    return r->getNum(a, b); // 依赖抽象层
}

void test1() {
    Rule *r;
    r = new RuleAdd();
    cout << doLogin(r) << endl;

    r = new RuleSub();
    cout << doLogin(r) << endl;
}
int main() {
    test1();
    return 0;
}
