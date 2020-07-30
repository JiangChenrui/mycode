#include <stdio.h>
#include <string>
#include <iostream>
#include "common.h"

int main() { 
    std::string imgPath = "build";
    std::cout << remove(imgPath.data()) << std::endl;
    return 0;
}