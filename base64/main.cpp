#include <string>
#include <iostream>
#include "Base64.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex>
using namespace std;

int main(){
    ifstream is("base64.txt", ios::binary);
    is.seekg(0, is.end);
    int size = is.tellg();
    is.seekg(0, is.beg);
    char buffer[size];
    is.read(buffer, size);

    // cout << buffer << endl; 
    cout << "file size:" << size << endl; 

    // char *buffer1 = new char[size];
    // buffer1 = reinterpret_cast<char*>(buffer);

    std::string re = {"^data:image/jpg;base64,|data:image/jpeg;base64,|data:image/png;base64,"};
    std::regex rex(re);
    // cout << std::regex_replace((char*)buffer, rex, "") << endl;
    std::string buffer1 = std::regex_replace((char*)buffer, rex, "");
    // cout << buffer1 << endl;

    // 编码
    const char* b;
    b = reinterpret_cast<const char*>((char*)buffer1.c_str());
    // string imgBase64 = Base64_Encode(b, size);
    // cout << "img base64 encode size:" << imgBase64.size() << endl;   
    // cout << imgBase64 << endl;

    // 解码
    // const char *str = imgBase64.c_str();   
    string imgdecode64 = Base64_Decode(b);
    const char *decode = imgdecode64.c_str();
    cout << "img decode size:" << imgdecode64.size() << endl; 
    FILE *fb;
    fb = fopen("test.jpg", "wb+");
    fwrite(decode , imgdecode64.size(), 1, fb);
    fclose(fb);   
    return 0;
}
