#ifndef MYSORT_HPP
#define MySORT_HPP
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// 查找和排序方法
typedef struct student {   
    int id;             // 学生编号
    char name[10];      // 学生姓名
    float score;        // 成绩
}Student;

// 顺序查找
int search(Student *stu, int n, int  key) {
    for (int i = 0; i < n; ++i) {
        if (stu[i].id == key)
            return i;
    }
    return -1;
}

/**
 * 折半查找
 * @param key 关键字顺序表
 * @param n 记录个数
 * @param k 要查找的关键字
 * @return
 */
int bin_search(int *key, int n, int k) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key[mid] == k)
            return mid;
        if (k > key[mid])
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

/**
 * 直接插入排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        int j = i - 1;
        // for (j; j >= 0; --j) {
        //     if (temp < arr[j]) {
        //         arr[j + 1] = arr[j];
        //     } else {
        //         break;
        //     }
        // }
        // arr[j + 1] = temp;

        while (j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
int* generateRandomArray(int n, int rangeL, int rangeR) {
    int* arr = new int[n];
    // 设置随机种子
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void printArray(vector<int> arr) {
    for (int a : arr) {
        cout << a << ' ';
    }
    cout << endl;
}

/**
 * 选择排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void selectSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = i, temp;
        for (int j = i; j < n; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

/**
 * 冒泡排序
 * 添加标志变量flag，进行交换flag为真，可以进入下一循环，为进行交换flag为假（数据已有序，无须再进行交换）循环终止。
 * @param arr 数组
 * @param n 数组元素个数
 */
void BubbleSort(int arr[], int n) {
    bool flag = true;
    for (int i = 0; i < n && flag; ++i) {
        flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * 希尔排序
 * 使用do-while是因为flag为2时已经有序，但是flag为1时不是有序的。
 * @param arr 数组
 * @param n 数组元素个数
 */
void shellSort(int arr[], int n) {
    int i, j, gap = n;
    bool flag = true;
    int temp;
    while(gap > 1) {
        gap = gap / 2;
        do {
            flag = false;
            for (i = 0; i < n - gap; ++i) {
                j = i + gap;
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    flag = true;
                }
            }
        } while(flag);
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 使用异或进行交换
// void swap(int &a, int &b) {
//     a ^= b;
//     b ^= a;
//     a ^= b;
// }

void quick(int arr[], int start, int end) {
    if (start >= end)
        return;
    int left = start, right = end, key = arr[start];
    // 进行循环，将小于基准元素的元素放到左边，大于基准元素的元素放到右边
    while (left < right) {
        while(left < right && arr[right] >= key)
            right--;
        while(left < right && arr[left] <= key)
            left++;
        swap(arr[left], arr[right]);
        // for (int i = 0; i < 10; ++i) {
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;
    }
    // 交换基准元素与left的位置，循环中先从右开始，因此left和right相等的位置为小于基准元素的值
    swap(arr[start], arr[left]);
    quick(arr, start, left - 1);
    quick(arr, left + 1, end);
}
/**
 * 快速排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void quickSort(int arr[], int n) {
    quick(arr, 0, n - 1);
}

int Partition(int *arr, int start, int end) {
    if (start == end)
        return start;
    int left = start, right = end, key = arr[start];
    while (left < right) {
        while (left < right && arr[right] >= key)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= key)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = key;
    return left;
}

/**
 * 非递归实现快排
 */
void quickSort2(int arr[], int n) {
    stack<int> st;
    st.push(0);
    st.push(n-1);
    while (!st.empty()) {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        int mid = Partition(arr, left, right);
        if (mid - 1 > left) {
            st.push(left);
            st.push(mid - 1);
        }
        if (mid + 1 < right) {
            st.push(mid + 1);
            st.push(right);
        }
    }
}

/**
 * 调整大顶堆
 * @param arr
 * @param i
 * @param len
 */
void adjust(int arr[], int i, int len) {
    int temp = arr[i];
    // 从i结点的左子结点开始，也就是2i+1
    for (int k = 2 * i + 1; k < len; k = k * 2 + 1) {
        // 如果左子结点小于右子结点，k指向右子结点
        if (k + 1 < len && arr[k] < arr[k + 1])
            k++;
        // 如果子结点大于父节点，将子结点的值赋给父节点
        if (arr[k] > temp) {
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = temp;
}

/**
 * 堆排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void headSort(int arr[], int n) {
    int i, temp;
    // 1.构建大顶堆
    for (i = n / 2; i >= 0; --i) {
        // 从第一个非叶子结点从下至上，从右至左调整结构
        adjust(arr, i, n);
    }
    // 2.调整堆结构并交换堆顶元素与末尾元素
    for (int j = n - 1; j > 0; --j) {
        swap(arr[0], arr[j]);
        adjust(arr, 0, j);
    }
}

/**
 * 归并排序
 * @param arr 数组
 * @param n 数组元素个数
 */
class MergeSort {
public:
    MergeSort(vector<int>& arr) {
        sort(arr, 0, arr.size()-1);
    }
    ~MergeSort();
private:
    void merge(vector<int>& arr, int start, int mid, int end) {
        vector<int> left(arr.begin()+start, arr.begin()+mid+1);
        vector<int> right(arr.begin()+mid+1, arr.begin()+end+1);
        int cur = start;
        for (int i = 0, j = 0; i < left.size(), j < right.size();) {
            if (left[i] < right[j]) {
                arr[cur++] = left[i++];
            } else {
                arr[cur++] = right[j++];
            }
            if (i == left.size()) {
                for (j; j < right.size();++j) arr[cur++] = right[j];
                break;
            }
            if (j == right.size()) {
                for (i; i < left.size();++i) arr[cur++] = left[i];
                break;
            }
        }
    }
    void sort(vector<int>& arr, int start, int end) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        sort(arr, start, mid);
        sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
};

bool isPrime(int num) {
    if (num < 0) 
        return false;
    if (num == 1 || num == 2) 
        return true;
    for (int i = 2; i < num; ++i) {
        if  (num % i == 0)
            return false;
    }
    return true;
}

/**
 * 穷举法输出1~100的素数
 */
void getPrime(int low, int high) {
    for (int i = low; i <= high; ++i) {
        if (isPrime(i))
            cout << i << ' ';
    }
    cout << endl;
}
#endif