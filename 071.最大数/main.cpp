#include <iostream>
#include "../include/node.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        // 使用自定义的排序规则对nums进行排序
        // 排序规则基于：将两个数字x和y拼接成字符串，如果x+y的字典序大于y+x，则x应排在y之前
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            // 将整数转换为字符串进行比较
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });

        // 特殊情况处理：如果排序后的第一个数字是0，说明整个数组全为0，直接返回"0"
        if (nums[0] == 0) {
            return "0";
        }

        // 初始化结果字符串
        string ret;

        // 遍历排序后的数字向量，将每个数字转换为字符串并拼接到结果字符串中
        for (int &x: nums) {
            ret += to_string(x);
        }

        // 返回最终得到的最大整数字符串
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1{10, 2};
    vector<int> v2{3, 30, 34, 5, 9};
    vector<int> v3{3, 34, 123};
    vector<int> v4{2, 3, 2, 1};
    vector<int> v5{34323, 3432};
    cout << s.largestNumber(v1) << endl;
    cout << s.largestNumber(v2) << endl;
    cout << s.largestNumber(v3) << endl;
    cout << s.largestNumber(v4) << endl;
    cout << s.largestNumber(v5) << endl;
    return 0;
}