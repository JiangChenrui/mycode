/**
 * string学习
 */
#include <iostream>
#include <string>
using namespace std;

void test01() {
    string s1;
    const char * str = "hello world";
    string s2(str);

    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}

// 字符串赋值
void test02() {
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hello C++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello C++", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(10, 'a');
    cout << "str6 = " << str6 << endl;
}

// 字符串拼接
void test03() {
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1 = " << str1 << endl;

    str1 += ':';
    cout << "str1 = " << str1 << endl;

    string str2 = " LOL";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << "str3 = " << str3 << endl;

    str3.append("game abcde", 4);
    cout << "str3 = " << str3 << endl;

    str3.append(str2);
    cout << "str3 = " << str3 << endl;

    str3.append("LOL DNF", 3, 4);
    cout << "str3 = " << str3 << endl;
}

// string查找和替换
void test04() {
    // 查找
    string str1 = "abcdefg";
    int pos = str1.find("de");
    if (pos != -1)
        cout << "pos = " << pos << endl;
    else
        cout << "未找到" << endl;
    
    // rfind
    pos = str1.rfind("de");
    if (pos != -1)
        cout << "pos = " << pos << endl;
    else
        cout << "未找到" << endl;

    // rfind和find的区别
    // rfind是从右向左找，find是从左向右

    // 替换
    // 从1号位置器3个字符替换位"1111"
    str1.replace(1, 3, "test1211");
    cout << "str1 = " << str1 << endl;
}

// 字符串比较
void test05() {
    string str1 = "hello";
    string str2 = "hello";

    if (str1.compare(str2) == 0) {
        cout << "str1 等于 str2" << endl;
    }
    else if (str1.compare(str2) > 0) {
        cout << "str1 大于 str2" << endl;
    }
    else if (str1.compare(str1) < 0) {
        cout << "str1 小于 str2" << endl;
    }
}

// string字符存取
void test06() {
    string str = "hello";
    cout << "str = " << str << endl;

    for (int i = 0; i < str.size(); ++i) {
        cout << str[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < str.size(); ++i) {
        cout << str.at(i) << ' ';
    }
    cout << endl;

    // 修改
    str[0] = 'x';
    cout << "str = " << str << endl;

    str.at(1) = 'x';
    cout << "str = " << str << endl;
}

// string插入和删除
void test07() {
    string str = "hello";
    cout << "str = " << str << endl;

    // 插入
    str.insert(1, "111");
    cout << "str = " << str << endl;

    // 删除
    str.erase(1, 3);
    cout << "str = " << str << endl;
}

// string子串获取
void test08() {
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;

    string email = "zhangsan@sina.com";
    // 从邮件地址中 获取 用户信息
    int pos = email.find("@");
    string usrName = email.substr(0, pos);
    cout << usrName << endl;
}
int main() {
    test08();
    return 0;
}