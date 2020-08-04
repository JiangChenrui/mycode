#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
using namespace std;

void sizeof_print() {
    cout << "short类型所占内存空间为：" << sizeof(short) << endl;
    cout << "int类型所占内存空间为：" << sizeof(int) << endl;
    cout << "long类型所占内存空间为：" << sizeof(long) << endl;
    cout << "long long类型所占内存空间为:" << sizeof(long long) << endl;
    cout << "float类型所占内存空间为：" << sizeof(float) << endl;
    cout << "double类型所占内存空间为：" << sizeof(double) << endl;
}
void char_study() {
    char ch = 'a';
    cout << ch << endl;
    cout << "char字符变量所占内存: " << sizeof(ch) << endl;
    cout << (int)ch << endl;
}

void str_study() {
    char str[] = "hello world";
    cout << str << endl;
    cout << "hello world 所占内存: " << sizeof(str) << endl;

    string str2 = "hello world";
    cout << str2 << endl;
    cout << "string hello world 所占内存: " << sizeof(str2) << endl;
}

void add_compare() {
    int a1 = 10;
    int b1 = a1++;
    cout << "a1 = " << a1 << " b1 = " << b1 << endl;

    /**
     * 前置++先自加如何进行表达式运算
     * 后置++先进行表达式运算再自加
     */
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << "a2 = " << a2 << " b2 = " << b2 << endl;

    int a3 = 10;
    int b3 = a3++ * 10;
    cout << "a3 = " << a3 << " b3 = " << b3 << endl;
}

/**
 * 生成随机数
 * @param range 随机数范围
 * @return
 */
int rand_number(int range) {
    srand((int)time(NULL));
    int ret = 0;
    for (int i = 0; i < 100; i++) {
        cout << rand() % range + 1 << endl;
        usleep(10000); //微秒，需要包含unistd头文件
    }
    return 0;
}