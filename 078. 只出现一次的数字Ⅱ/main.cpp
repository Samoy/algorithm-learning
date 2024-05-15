#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.cn/problems/single-number-ii/solutions/8944/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/?envType=study-plan-v2&envId=selected-coding-interview
    int singleNumber(const vector<int> &nums) {
        int ones = 0, twos = 0;  // 初始化两个变量，ones用于存储只出现一次的数字，twos用于存储出现两次的数字
        for (int num: nums) {  // 遍历数组中的每个元素
            // 更新ones：使用异或操作和位操作更新ones，清除其中出现两次的数字
            ones = ones ^ num & ~twos;

            // 更新twos：同样使用异或操作和位操作更新twos，清除其中出现一次的数字
            twos = twos ^ num & ~ones;
        }
        return ones;  // 遍历结束后，ones中存储的就是只出现一次的数字，返回ones
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.singleNumber({2, 2, 3, 2}) << endl;
    cout << s.singleNumber({0, 1, 0, 1, 0, 1, 99}) << endl;
    return 0;
}