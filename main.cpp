#include <string>
#include <iostream>
#include "common.h"

int main() { 
    char dir[128] = {"test.zip"};
    std::cout << checkDirIsZip(dir) << std::endl;
    return 0;
}