#include <time.h>
#include <iostream>
#include <cstring>
#include <sys/time.h>

using namespace std;

int main() {
    struct tm tm_;
    char buf[128] = {0};
    struct timeval time_tv;
    time_t t;
    strcpy(buf, "2020-07-22 13:15:20");
    //strtime将tm转为字符串
    // strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm_);
    // strptime将字符串时间转为tm
    strptime(buf, "%Y-%m-%d %H:%M:%S", &tm_);
    // mktime将tm转为time_t
    t = mktime(&tm_);
    time_tv.tv_sec = t;
    time_tv.tv_usec = 0;
    settimeofday(&time_tv, NULL);
    return 0;
}