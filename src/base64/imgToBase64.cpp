#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/stat.h>
 
 
using namespace std;
/**
 * Base64 编码/解码
 */
class Base64{
private:
    std::string _base64_table;
    static const char base64_pad = '=';
public:
    Base64()
    {
        _base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; /*这是Base64编码使用的标准字典*/
    }
    /**
     * 这里必须是unsigned类型，否则编码中文的时候出错
     */
    std::string Encode(const unsigned char * str,int bytes);
    std::string Decode(const char *str,int bytes);
    void Debug(bool open = true);
};
 
std::string Base64::Encode(const unsigned char * str,int bytes) {
    int num = 0,bin = 0,i;
    std::string _encode_result;
    const unsigned char * current;
    current = str;
    while(bytes > 2) {
        _encode_result += _base64_table[current[0] >> 2];
        _encode_result += _base64_table[((current[0] & 0x03) << 4) + (current[1] >> 4)];
        _encode_result += _base64_table[((current[1] & 0x0f) << 2) + (current[2] >> 6)];
        _encode_result += _base64_table[current[2] & 0x3f];
 
        current += 3;
        bytes -= 3;
    }
    if(bytes > 0)
    {
        _encode_result += _base64_table[current[0] >> 2];
        if(bytes%3 == 1) {
            _encode_result += _base64_table[(current[0] & 0x03) << 4];
            _encode_result += "==";
        } else if(bytes%3 == 2) {
            _encode_result += _base64_table[((current[0] & 0x03) << 4) + (current[1] >> 4)];
            _encode_result += _base64_table[(current[1] & 0x0f) << 2];
            _encode_result += "=";
        }
    }
    return _encode_result;
}
std::string Base64::Decode(const char *str,int length) {
       //解码表
    const char DecodeTable[] =
    {
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -2, -2, -2,
        -2,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2,
        -2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
        -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
    };
    int bin = 0,i=0,pos=0;
    std::string _decode_result;
    const char *current = str;
    char ch;
    while( (ch = *current++) != '\0' && length-- > 0 )
    {
        if (ch == base64_pad) { // 当前一个字符是“=”号
            /*
            先说明一个概念：在解码时，4个字符为一组进行一轮字符匹配。
            两个条件：
                1、如果某一轮匹配的第二个是“=”且第三个字符不是“=”，说明这个带解析字符串不合法，直接返回空
                2、如果当前“=”不是第二个字符，且后面的字符只包含空白符，则说明这个这个条件合法，可以继续。
            */
            if (*current != '=' && (i % 4) == 1) {
                return NULL;
            }
            continue;
        }
        ch = DecodeTable[ch];
        //这个很重要，用来过滤所有不合法的字符
        if (ch < 0 ) { /* a space or some other separator character, we simply skip over */
            continue;
        }
        switch(i % 4)
        {
            case 0:
                bin = ch << 2;
                break;
            case 1:
                bin |= ch >> 4;
                _decode_result += bin;
                bin = ( ch & 0x0f ) << 4;
                break;
            case 2:
                bin |= ch >> 2;
                _decode_result += bin;
                bin = ( ch & 0x03 ) << 6;
                break;
            case 3:
                bin |= ch;
                _decode_result += bin;
                break;
        }
        i++;
    }
    return _decode_result;
}
 
int file_size(char* filename)
{
    FILE *fp=fopen(filename, "r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    return size;
}
 
int file_size2(char* filename)
{
    // TODO stat是啥东西
    struct stat statbuf;
    stat(filename,&statbuf);
    int size=statbuf.st_size;
    return size;
}
 
int main()
{
    string normal,normaltest,encoded,encodedtest;
    int i,len,datalen;
    FILE *fa, *fb;
    Base64 *base = new Base64();
 
    ifstream f;
 
    //使用两种方法打开文件
    f.open("6.jpg", ios_base::in | ios_base::binary);
    if( (fa = fopen("6.jpg", "ab+")) == NULL )
    {
        cout << "Error!" <<endl;
    }
 
 
    //使用三种方法获取文件大小
    int asd_file_size1 = file_size((char*)"test.jpg");
    cout << "File_size1:" << asd_file_size1 <<endl;
 
    int asd_file_size2 = file_size2((char*)"test.jpg");
    cout << "File_size2:" << asd_file_size2 <<endl;
 
    f.seekg(0, std::ios_base::end);
    std::streampos sp = f.tellg();
    int size_of_file = sp;
    cout << "File_size3:" << size_of_file << endl;
 
    unsigned char *buffer1[size_of_file];
    char buffer2[size_of_file];
 
    //读取文件到buffer内
    f.seekg(0, std::ios_base::beg);     //读之前先将偏移量设置到文件开头
    f.read((char*)buffer1, size_of_file);
    fread(buffer2, sizeof(char), asd_file_size1, fa);
    fclose(fa);
	cout << "读取图片二进制：" << buffer1 << endl;

    const unsigned char* b, *c;
    //因为这个方法编码要求const unsigned char*，所以要将buffer转成相应的类型
    b = reinterpret_cast<const unsigned char*>(buffer1);
    c = reinterpret_cast<const unsigned char*>(buffer2);
 
    //编码
    encoded = base->Encode(b, size_of_file);
    encodedtest = base->Encode(c, size_of_file);
    cout << "Encode_Len:" << encoded.length() <<endl;
    cout << "Encodetest_Len:" << encodedtest.length() <<endl;

    //将编码后的数据保存成文件
    ofstream foutEnc("encode.txt", ios_base::out|ios_base::binary);
    if(!foutEnc)
        cout << "error" << endl;
    else{
        cout << "Success encode!" << endl;
        foutEnc.write(encoded.c_str(), encoded.size());
    }
    foutEnc.close();
 
    //参数要求，转换成const char*后解码
    const char * str1 = encoded.c_str();
    const char * str2 = encodedtest.c_str();
    normal = base->Decode(str1, strlen(str2));
    normaltest = base->Decode(str2, strlen(str2));
    cout << "Decode_Len:" << normal.length() <<endl;
    cout << "Decodetest_Len:" << normaltest.length() <<endl;
 
    const char *qwe = normal.c_str();
    const char *asd = normaltest.c_str();
 
    ofstream foutasd("decode.jpg", ios_base::out|ios_base::binary);
    if (!foutasd)
    {
        cout << "error" << endl;
    }
    else
    {
        cout << "Success!" << endl;
        foutasd.write(qwe, size_of_file);
    }
    foutasd.close();
 
    fb = fopen("decode1.jpg", "wb+");
    fwrite(asd , size_of_file, 1, fb);
    fclose(fb);
 
    return 0;
}