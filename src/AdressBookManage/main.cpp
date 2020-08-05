#include "AdressBookManage.h"
#include <iostream>

int main() {

    AddressBooks abs;
    // 初始化通讯录
    initAddressBooks(abs);

    int select = 0;

    for(;;) {
        //显示菜单
        showMenu();
        std::cin >> select;
        switch (select) 
        {
            case 1:
                addPerson(&abs);
                break;
            case 2:
                printPerson(abs);
                break;
            case 3:
                delPerson(abs);
                break;
            case 4:
                selectPerson(abs);
                break;
            case 5:
                modifyPerson(abs);
                break;
            case 6:
                clearAddressBooks(abs);
                break;
            case 0:
                std::cout << "退出通讯录管理系统" << std::endl;
                return 0;
            default:
                std::cout << "输入有误" << std::endl;
                break;
        }
    }
    return 0;
}