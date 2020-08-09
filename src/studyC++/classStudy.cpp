#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    void showStudent() {
        cout << "姓名： " << name << " 学号：" << id << endl;
    }

    void setName(string name) {
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

private:
    string name;
    int id;
};

// 立方体类
class Cube {
public:
    void setL(int l) {
        m_L = l;
    }

    void setH (int h) {
        m_H = h;
    }

    void setW( int w) {
        m_W = w;
    }

    int getL() {
        return m_L;
    }

    int getH() {
        return m_H;
    }

    int getW() {
        return m_W;
    }

    int calculateS() {
        return 2 * (m_H * m_W + m_L * m_W + m_H * m_L);
    }

    int calculateV() {
        return m_H * m_L * m_W;
    }
    
    bool isSameByClass(Cube &c) {
        if (m_L == c.getL() && m_H == c.getH() && m_W == c.getW()) {
            cout << "c1和c2是相等的" << endl;
            return true;
        }
        else {
            cout << "c1和c2是不等的" << endl;
            return false;
        }
    }
private:
    int m_L;    //长
    int m_H;    //高
    int m_W;    //宽
};

// 点和圆的关系
class Point {
public:
    // 构造函数
    // 函数名与类名相同
    // 构造函数可以有参数，可以发生重载
    // 创建对象时，构造函数会自动调用，而且只调用一次
    // 构造函数分为有参构造和无参构造，拷贝构造(实参传形参会调用)
    Point() {
        cout << "调用构造函数" << endl;
    }
    Point(int x, int y) {
        m_X = x;
        m_Y = y;
        cout << "有参构造函数" << endl;
    }
    Point(const Point &p) {
        m_X = p.m_X;
        m_Y = p.m_Y;
        cout << "拷贝构造函数" << endl;
    }
    // 初始化列表
    // Point(int x, int y) : m_X(x), m_Y(y) {}
    // 析构函数
    // 没有返回值，不写void
    // 函数名与类名相同，在名称前加~
    // 析构函数不可以有参数，不可以发生重载
    // 对象在销毁前会自动调用析构函数，而且只会调用一次
    ~Point() {
        // cout << "析构函数" << endl;
    }
    void setX(int x) {
        m_X = x;
    }
    void setY(int y) {
        m_Y = y;
    }

    int getX() {
        return m_X;
    }
    int getY() {
        return m_Y;
    }

private:
    int m_X;
    int m_Y;
};

class Circle {
public:
    void setR(int R) {
        m_R = R;
    }
    void setCenter(Point & center) {
        m_Center = center;
    }

    int getR() {
        return m_R;
    }
    Point getCenter() {
        return m_Center;
    }

private:
    int m_R;
    Point m_Center;
};

void isIncircle(Point &p, Circle &c) {
    // 计算点到圆心的距离
    int distance = 
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    int rDistance = c.getR() * c.getR();

    if (distance == rDistance) {
        cout << "点在圆上" << endl;
    } else if (distance < rDistance) {
        cout << "点在圆内" << endl;
    } else {
        cout << "点在圆外" << endl;
    }
}

// 深拷贝与浅拷贝
class Person {
    friend void family(Person &person);  // 友元函数
    friend Point;
    friend int Point::getX();
    friend ostream & operator<< (ostream &cout, Person &p);

public:
    Person() {
        m_Height = new int(0);
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age, int height) {
        m_Age = age;
        m_Height = new int(height); // 申请堆区空间
        cout << "Person的有参构造函数调用" << endl;
    }
    Person(const Person &p) {
        cout << "Person拷贝构造函数调用" << endl;
        m_A = p.m_A;
        m_Age = p.m_Age;
        // m_Height = p.m_Height 编译器调用的拷贝构造函数
        m_Height = new int(*p.m_Height);
    }
    ~Person() {
        if (m_Height != NULL) {
            delete m_Height;
        }
        cout << "析构函数" << endl;
    }

    void showNameClass() {
        cout << "This is a class" << endl;
    }

    void showPersonAge() {
        if (this == NULL) {
            return;
        }
        cout << "age = " << this->m_Age << endl;
    }

    void showPerson() const {
        // this指针的本质是指针常量，指针的指向不可以修改
        this->m_B = 100;
    }

    // 运算符重载
    Person operator+ (Person &p) {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_Age = p.m_Age;
        temp.m_Height = new int(*p.m_Height);
        return temp;
    }

    // 重载 赋值运算符
    Person & operator= (Person &p) {
        // 编译器提供浅拷贝
        // this->m_Height = p.m_Height;

        // 应该先判断是否有属性在堆区，如果有先释放干净，然后在深拷贝
        if (m_Height != NULL) {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "重载运算符=" << endl;
        m_A = p.m_A;
        m_Age = p.m_Age;
        m_Height = new int (*p.m_Height);
        return *this;
    }

    int m_A;
private:
    int *m_Height;
    int m_Age;
    mutable int m_B;  // 添加mutable后，成员可以在常函数和常对象中修改
};

class MyInteger {
    friend ostream & operator<< (ostream &cout, MyInteger myint);
public:
    MyInteger() {
        m_Num = 0;
    }

    // 重置前置++
    MyInteger & operator++ () {
        m_Num ++;
        return *this;
    }

    MyInteger operator++ (int) {
        // 先记录结果
        MyInteger temp = *this;
        // 后递增
        this->m_Num ++;
        // 返回记录结果
        return temp;
    }
private:
    int m_Num;
};

// 只能利用全局函数重载左移运算符
ostream & operator<< (ostream &cout, Person &p) {
    cout << "m_A = " << p.m_A << endl;
    cout << "m_Age = " << p.m_Age << endl;
    cout << "m_Height = " << *p.m_Height;
    return cout;
}

ostream & operator<< (ostream &cout, MyInteger myint) {
    // MyInteger 使用引用会使后置++输出失败
    cout << "运算符重载" << endl;
    cout << myint.m_Num;
    return cout;
}

void test1() {
    Cube c1, c2;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);
    cout << c1.calculateS() << endl;
    cout << c1.calculateV() << endl;
    c2.setH(10);
    c2.setL(10);
    c2.setW(10);
    c1.isSameByClass(c2);
}

void test2() {
    Circle c;
    Point p, center;
    center.setX(10);
    center.setY(0);
    c.setR(10);
    c.setCenter(center);
    p.setX(10);
    p.setY(9);
    isIncircle(p, c); 
}

void test3() {
    // 构造函数
    // 1.括号法
    Point p;
    Point p1(10, 20);
    cout << p1.getX() << endl;
    Point p2(p1);
    cout << p2.getX() << endl;
    // 2.显式法
    Point p3 = Point(10, 20);
    Point(10, 20); // 匿名对象，当前行之心并回收
    // 3.隐式转换法
    Point p4 = {10, 20};
}

// void test4() {
//     Person p1(10, 160);
//     cout << p1.m_Age << " " << *p1.m_Height << endl;
//     Person p2(p1);
//     cout << p2.m_Age << " " << *p2.m_Height << endl;
// }

void family(Person &person) {
    cout << person.m_A << endl;
    cout << person.m_Age << endl;
}

void testInt() {
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main() {
    Person p1(10, 4);
    p1.m_A = 10;

    Person p2, p3;
    p3 = p2 = p1;
    cout << p3 << endl;
    return 0;
}