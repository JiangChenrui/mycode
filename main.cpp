#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;
int main() {
    const char *dir = "/home/workspace/mycode/readme.md";
    cout << access(dir, 0) << endl;
    return 0;
}