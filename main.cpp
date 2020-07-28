#include <string>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <sstream> 
#include <iomanip> 

using namespace std;

/**
 * 将字符串分割
 * @param strStreams
 * @param streams
 * @return
 */
int stringToArray(std::string strStreams, std::vector <int> &streams) {
    if (strStreams.empty()) {
        return -1;
    }
    //用,分割strStreams
    const char *split = ",";
    char *p;
    p = strtok((char*)strStreams.data(), split);
    while(p) {
        streams.push_back(std::stoi(p));
        p = strtok(NULL, split);
    }
    return 0;
}
float round(float f, int bits) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(bits) << f; 
    ss >> f; 
    return f;
}
int main() { 
    std::string filename = "hello.jpg";
    string suffixStr = filename.substr(filename.find_last_of('.') + 1);
    cout << suffixStr << endl;
    return 0;
}