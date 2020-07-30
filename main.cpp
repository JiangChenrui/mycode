#include <stdio.h>

#include <iostream>
#include <string>

#include "common.h"

int main() {
    std::string imgPath = "build";
    std::cout << remove(imgPath.data()) << std::endl;
    return 0;
}