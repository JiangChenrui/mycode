#include <iostream>
using namespace std;

/**
 * 输出1000以内的水仙花数
 * 水仙花数为位数的3次方之和与原数相等
 */
void num_of_daffodils() {
    int num = 1;
    while (num++ < 1000) {
        int a, b, c = 0;
        a = num % 10;
        b = num / 10 % 10;
        c = num / 100 % 10;

        if (a*a*a + b*b*b + c*c*c == num) {
            cout << num << endl;
        }
    }
}

/**
 * 敲桌子，位数有7或者是7的倍数
 */
void knock_table() {
    for (int i = 0; i < 100; ++i) {
        if (i % 7 == 0 && i != 0) {
            goto KNOCK;
        }
        if (i % 10 == 7) {
            goto KNOCK;
        }
        if (i / 10 % 10 == 7) {
            goto KNOCK;
        }
        cout << i << endl;
        continue;
    KNOCK:
        cout << "敲桌子" << endl;
    }
}

/**
 * 输出乘法口决表
 */
void out_multiplication() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j << "x" << i << "=" << i*j << "\t";
        }
        cout << endl;
    }
}