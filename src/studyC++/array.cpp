#include <iostream>
#include <vector>
using namespace std;

void arr_out() {
    int arr[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << arr << endl;
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << endl;
    }
    int arr1[5] = {10, 20, 30};
    cout << arr1 << endl;
    for (int i = 0; i < 5; ++i) {
        cout << arr1[i] << endl;
    }
}

void bubble_sort(int *num, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (num[j] > num[j+1]) {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    for (int i=0; i < len; ++i) {
        cout << num[i] << " ";
    }
    cout << endl;
}

void two_array() {
    int arr[2][3];
    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};
    int arr4[][3] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr4[i][j] << " ";
        }
        cout << endl;
    }
}

// 输出一维数组
void PrintArray(int* arr, int len) {
    cout << "输出一维数组" << endl;
    for (int i = 0; i < len; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

// 输出二维数组
void PrintArray(int **arr, int m, int n) {
    cout << "输出二维数组" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

/**
 * c++动态申请多维数组
 * 第一种 malloc/free
 * @param len 一维数组大小
 * @param m 二维数组行数
 * @param n 二维数组列数
 */
void dynamicCreate1Array(int len, int m, int n) {
    // 一维数组
    int *p;
    p = (int*)malloc(sizeof(int)*len);    // 动态开辟m大小的数组
    cout << "malloc/free" << endl;
    PrintArray(p, len);
    // 释放空间
    free(p);

    // 二维数组
    int **p2;
    p2 = (int**)malloc(sizeof(int*)*m);         //开辟行
    for (int i = 0; i < m; ++i) {
        p2[i] = (int*)malloc(sizeof(int*)*n);   //开辟列
    }
    PrintArray(p2, m, n);
    // 释放空间
    for (int i = 0; i < m; ++i)
        free(*(p2+i));
}

/**
 * c++动态申请多维数组
 * 第二种 new/delete
 * @param len 一维数组大小
 * @param m 二维数组行数
 * @param n 二维数组列数
 */
void dynamicCreate2Array(int len, int m, int n) {
    // 开辟空间
    int *p = new int[len];      // 只分配空间未进行初始话
    int *p1 = new int[len]();    // 分配空间并进行初始化
    cout << "new/delete" << endl;
    PrintArray(p, len);
    PrintArray(p1, len);
    // 释放空间
    delete[] p;
    delete[] p1;

    int **p2 = new int*[m];     // 开辟行
    for (int i = 0; i < m; ++i)
        p2[i] = new int[n]();     // 开辟列
    PrintArray(p2, m, n);
    // 释放空间
    for (int i = 0; i < m; ++i)
        delete[] p2[i];
    delete[] p2;
}

/**
 * c++动态申请多维数组
 * 第三种 
 * @param len 一维数组大小
 * @param m 二维数组行数
 * @param n 二维数组列数
 */
void dynamicCreate3Array(int len, int m, int n) {
    vector<int> p(len);
    cout << "vector" << endl;
    cout << "输出一维数组" << endl;
    for (int i = 0; i < p.size(); ++i)
        cout << p[i] << ' ';
    cout << endl;

    vector<vector<int> > p2(m, vector<int>(n));
    cout << "输出二维数组" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << p2[i][j] << ' ';
        cout << endl;
    }
}

// int main() {
//     dynamicCreate1Array(10, 10, 20);
//     dynamicCreate2Array(10, 10, 20);
//     dynamicCreate3Array(10, 10, 20);
//     return 0;
// }