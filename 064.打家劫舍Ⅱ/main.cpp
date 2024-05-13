#include "../include/node.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        // 如果数组为空，无法偷窃，返回0
        if (nums.empty()) return 0;

        // 如果数组只有一个元素，只能偷这一个，返回该元素值
        if (nums.size() == 1) return nums[0];

        // 分别计算不偷第一个房间和不偷最后一个房间的情况，取两者中的较大值作为答案
        return max(myRob(vector<int>(nums.begin(), nums.end() - 1)),
                   myRob(vector<int>(nums.begin() + 1, nums.end())));
    }

    // 动态规划辅助函数，处理一个连续的子数组
    int myRob(const vector<int> &nums) {
        // 初始化动态规划变量，pre表示不偷当前房屋的最大偷窃金额，cur表示包括当前房屋的最大偷窃金额，tmp用于临时存储cur的值
        int pre = 0, cur = 0, tmp;

        // 遍历子数组中的每个房屋
        for (int num: nums) {
            // 保存当前的cur值到tmp
            tmp = cur;

            // 更新cur，取pre + num和cur的较大值
            cur = max(pre + num, cur);

            // 更新pre，将tmp（之前cur的值）赋给pre
            pre = tmp;
        }

        // 返回最后的cur，即在子数组中能偷窃到的最大金额
        return cur;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1 = {2, 3, 2};
    vector<int> v2 = {1, 2, 3, 1};
    vector<int> v3 = {1, 2, 3};
    cout << s.rob(v1) << endl;
    cout << s.rob(v2) << endl;
    cout << s.rob(v3) << endl;
    return 0;
}