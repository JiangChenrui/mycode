#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include "MySort.hpp"
#include <map>
using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums;
//     for (int i = 0; i < n; ++i) {
//         int temp;
//         cin >> temp;
//         nums.push_back(temp);
//     }
//     sort(nums.begin(), nums.end());
//     int end = n - 1;
//     int start = 0;
//     int mid = 0;
//     bool flag = false;
//     while (start < end && !flag) {
//         for (; start < end && !flag; ++start) {
//             int sub = nums[end] - nums[start];
//             for (int i = 0; i < end && i != start && !flag; ++i) {
//                 if (2 * nums[i] == sub) {
//                     mid = nums[i];
//                     flag = true;
//                     cout << nums[end] << ' ' << nums[start] << ' ' << mid << endl;
//                 }
//             }
//         }
//         start = 0;
//         end--;
//     }
//     if (!flag)
//         cout << 0 << endl;
//     return 0;
// }


// int main() {
//     string nums;
//     cin >> nums;
//     int n;
//     cin >> n;
//     int len = nums.size();
//     if (len % n != 0) {
//         cout << pow(10, len / n) - len % n + 1 << endl;
//         return 0;
//     }
//     int res = 0;
//     int mp[10] = {0};
//     for (auto i : nums) {
//         mp[i - '0']++;
//     }
//     int small = 0;
//     for (int i = 0; i < 10; ++i) {
//         if (mp[i] > n) {
//             res = res * 10 + i;
//             mp[i] -= n;
//             i--;
//         }
//     }
//     for (int i = 0; i < 10; ++i) {
//         if (mp[i] != 0) {
//             small = i;
//             break;
//         }
//     }
//     res = res * 10 + small;
//     cout << res << endl;
//     return 0;
// }

int inputTest() {
    int n, m;
    cin >> n >> m;
    map<char, int> distance;
    for (int i = 0; i < n; ++i) {
        char id;
        int dis;
        cin >> id >> dis;
        distance[id] = dis;
    }
    
    for (int i = 0; i < m; ++i) {
        char aId;
        char bId;
        int dis;
        cin >> aId >> bId >> dis;
        
    }
    return 0;
}

vector<string> split(const string &str, const string &splitChar) {
    vector<string> res;
    if (str == "")
        return res;
    string strs = str + splitChar;
    size_t pos = strs.find(splitChar);

    while (pos != strs.npos) {
        string temp = strs.substr(0, pos);
        if (temp != "")
            res.push_back(temp);
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(splitChar);
    }
    return res;
}

int main() {
    string input = "  Hello  world  ";
    string splitChar = " ";
    split(input, splitChar);

    vector<int> arr(100000, 1);
    for (int i = 1; i < arr.size(); ++i) {
        arr[i] = arr[i] + arr[i-1];
    }
    random_shuffle(arr.begin(), arr.end());
    MergeSort* MergeS = new MergeSort(arr);
    printArray(arr);
    cout << endl;
    return 0;
}