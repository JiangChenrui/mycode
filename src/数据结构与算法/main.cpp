#include <iostream>
#include "Sqlist.hpp"
#include "LinkList.hpp"
#include "stack.hpp"
#include "MyQueue.hpp"
#include "MyTree.hpp"
#include "MySort.hpp"
#include "MyAlgorithm.hpp"

using namespace std;

void test01() {
    Sqlist L(100);
    for (int i = 0; i < 10; ++i) {
        L.Insert(i+1, 10*i);
    }
    L.PrintSqlist();
    L.Delete(5);
    L.PrintSqlist();
    L.Remove();
    L.PrintSqlist();
}

void test02() {
    LinkList l;
    int i;
    do
    {
        cout << "1.创建单链表\t2.遍历单链表\t3.获取链表长度\t4.判断链表是否为空\t5.获取节点\n";
        cout << "6.尾部插入\t7.指定位置插入\t8.头部插入\t9.尾部删除元素\n";
        cout<<"10.删除所有元素\t11.删除指定元素\t12.头部删除\t0.退出" << endl;
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
        case 1:
            int n;
            cout << "请输入单链表的长度: ";
            cin >> n;
            l.CreateLinkList(n);
            break;
        case 2:
            l.TravalLinkList();
            break;
        case 3:
            cout << "该单链表的长度为: " << l.GetLength() << endl;
            break;
        case 4:
            if (l.IsEmpty())
                cout << "该单链表是空表" << endl;
            else
                cout << "该单链表不是空表" << endl;
            break;
        case 5:
            DataType data;
            cout << "请输入要获取节点的值: ";
            cin >> data;
            if (l.Find(data) == NULL) {
                cout << "未找到该节点" << endl;
                break;
            }
            cout << "该节点的值为" << l.Find(data)->data << endl;
            break;
        case 6:
            DataType endData;
            cout << "请输入要在尾部插入的值: ";
            cin >> endData;
            l.InsertElemAtEnd(endData);
            break;
        case 7:
            DataType pointData;
            int index;
            cout << "请输入要插入的数据: ";
            cin >> pointData;
            cout << "请输入要插入数据的位置: ";
            cin >> index;
            l.InsertElemAtIndex(pointData, index);
            break;
        case 8:
            DataType headData;
            cout << "请输入要在头部插入的值: ";
            cin >> headData;
            l.InsertElemAtHead(headData);
            break;
        case 9:
            l.DeleteElemAtEnd();
            break;
        case 10:
            l.DeleteAll();
            break;
        case 11:
            DataType pointDeleteData;
            cout << "请输入要删除的数据: ";
            cin >> pointDeleteData;
            l.DeleteElemAtPoint(pointDeleteData);
            break;
        case 12:
            l.DeleteElemAtHead();
            break;
        default:
            break;
        }
    }while (i != 0);
}

void test03() {
    Stack<char> p(5);
    p.Push('s');
    p.Push('t');
    p.Push('a');
    p.Push('c');
    p.Push('k');
    p.StackTraverse();

    char ele;
    p.Pop(ele);
    cout << ele << endl;
    p.StackTraverse();
}

void test04() {
    MyQueue<char> q;
    q.InQueue('q');
    q.InQueue('u');
    q.InQueue('e');
    q.InQueue('u');
    q.InQueue('e');
    q.QueueTraverse();
    q.OutQueue();
    q.QueueTraverse();
}

void test05() {
    Tree tree(16);//分配十六个节点

    tree.addNode(0, 1);
    tree.addNode(0, 2);
    tree.addNode(0, 3);
    tree.addNode(0, 4);
    tree.addNode(0, 5);
    tree.addNode(0, 6);
    tree.addNode(3, 7);
    tree.addNode(4, 8);
    tree.addNode(4, 9);
    tree.addNode(5, 10);
    tree.addNode(5, 11);
    tree.addNode(5, 12);
    tree.addNode(6, 13);
    tree.addNode(9, 14);
    tree.addNode(9, 15);

    cout << "Tree1: " << endl;
    tree.preOrder();
    tree.print();    

    Tree tree2(9);
    tree2.addNode(0, 1);
    tree2.addNode(0, 2);
    tree2.addNode(1, 3);
    tree2.addNode(1, 4);
    tree2.addNode(2, 5);
    tree2.addNode(3, 6);
    tree2.addNode(5, 7);
    tree2.addNode(5, 8);

    cout << "Tree2: " << endl;
    tree2.preOrder();
    tree2.print();
}

void SortTest01() {
    Student stu[4] = {
        {1004, "TOM", 100},
        {1002, "LILY", 95},
        {1001, "ANN", 93},
        {1003, "LUCY", 98}
    };
    int addr;
    addr = search(stu, 4, 1001);
    if (addr == -1) {
        cout << "查无此人" << endl;
        return;
    }
    cout << "学号：" << stu[addr].id << endl;
    cout << "姓名：" << stu[addr].name << endl;
    cout << "分数：" << stu[addr].score << endl;
}

void SortTest02() {
    int arr[10] = {2, 3, 5, 7, 8, 10, 12, 15, 19, 20};
    cout << "数组输出" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
        cout << arr[i] << ' ';
    cout << endl;
    int n, addr;
    cout << "请输入查找的数" << endl;
    cin >> n;
    addr = bin_search(arr, 10, n);
    if (addr != -1) {
        cout << n << " 查找成功，位于" << addr << endl;
    } else  {
        cout << "查找失败" << endl;
    }
}

void SortTest03() {
    int N = 20000;
    int *arr = generateRandomArray(N, 2, 100000);
    // insertSort(arr, N);
    // selectSort(arr, N);
    // BubbleSort(arr, N);
    // shellSort(arr, N);
    // quickSort(arr, N);
    quickSort2(arr, N);
    // headSort(arr, N);
    printArray(arr, N);
}

void AlgorithmTest01() {
    // cout << P(6, 6) << endl;
    int Q[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            Q[i][j] = 0;
    Queen(0, Q);
    cout << count << endl;
}

void AlgorithmTest02() {
    cout << UpStairs(20) << endl;
    cout << UpStairs2(20) << endl;
}

void AlgorithmTest03() {
    cout << miniDistance("horse", "ros") << endl;
}

int main() {
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // SortTest01();
    // SortTest02();
    // SortTest03();
    // getPrime(1, 100);
    // AlgorithmTest02();
    // AlgorithmTest03();
    // testFindKth();
    // cout << isValid("((())])]") << endl;
    vector <int> A = {1, 2, 3, 4, 5};
    vector <int> B = multiply(A);
    for (int i = 0; i < B.size(); ++i)
        cout << B[i] << ' ';
    cout << endl;
    return 0;
}