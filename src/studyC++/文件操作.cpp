#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// 文件操作三大类
// 1.ofstream:写操作
// 2.ifstream:读操作
// 3.fstream: 读写操作

// 写文件步骤
// 打开头文件->创建流对象->打开文件->写数据->关闭文件
void test01() {
    ofstream ofs;

    ofs.open("test.txt", ios::out);
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;

    ofs.close();
}

void test02() {
    ifstream ifs;

    ifs.open("test.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    // 读数据
    // 第一种
    // char buf[1024] = {0};
    // while (ifs >> buf) {
    //     cout << buf << endl;
    // }

    // 第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf))) {
    //     cout << buf << endl;
    // }

    // 第三种
    string buf;
    while (getline(ifs, buf)) {
        cout << buf << endl;
    }

    // 第四种
    // char c;
    // while ((c = ifs.get()) != EOF) { // EOF end of file
    //     cout << c;
    // }

    ifs.close();
}

// 二进制文件 写文件
class Person {
   public:
    char m_name[64];
    int m_age;
};

void test03() {
    ofstream ofs;

    ofs.open("person.txt", ios::out | ios::binary);
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));

    ofs.close();
}

void test04() {
    ifstream ifs;

    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名：" << p.m_name << endl;
    cout << "年龄：" << p.m_age << endl;

    ifs.close();
}

int main() {
    test04();
    return 0;
}