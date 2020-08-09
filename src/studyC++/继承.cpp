#include <iostream>

using namespace std;

class Base {
   public:
    Base() { m_A = 100; }
    int m_A;

   protected:
    int m_B;

   private:
    int m_C;
};

class Son : public Base {
   public:
    Son() { m_A = 200; }
    int m_A;
};

void test01() {
    // 父类中的所以非静态成员属性都会被子类继承下去
    Son s1;
    cout << "size of Son = " << sizeof(s1) << endl;
    cout << s1.m_A << endl;
    cout << s1.Base::m_A << endl;
}

// 使用虚继承解决菱形继承问题
// 动物类
class Animal {
public:
    int m_Age;
};
// 羊类
class Sheep : virtual public Animal{};
// 驼类
class Tuo : virtual public Animal{};
// 羊驼类
class SheepTuo : public Sheep, public Tuo {};

void test02() {
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    cout << "st.Sheep.m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo.m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;
}

int main() {
    test02();
    return 0;
}