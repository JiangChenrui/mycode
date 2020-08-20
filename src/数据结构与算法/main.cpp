#include <iostream>
#include "Sqlist.hpp"
#include "LinkList.hpp"

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

int main() {
    // test01();
    test02();
    return 0;
}