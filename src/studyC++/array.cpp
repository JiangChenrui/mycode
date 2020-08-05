#include <iostream>
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