#include "../include/node.h"
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        // 检查输入数组是否为空，若为空则无法偷窃，返回0
        if (nums.empty()) {
            return 0;
        }

        // 初始化两个动态规划变量，dp0表示不包括当前房屋的最大偷窃金额，dp1表示包括当前房屋的最大偷窃金额
        int dp0 = 0, dp1 = nums[0];

        // 遍历数组，从第二个元素开始到最后一个元素
        for (int i = 1; i < nums.size(); ++i) {
            // 保存dp0的当前值，防止在更新dp1时被覆盖
            int temp = dp0;

            // 更新dp0，取dp0和dp1中的较大值
            dp0 = max(dp0, dp1);

            // 更新dp1，考虑当前房屋是否偷窃
            // 如果不偷窃当前房屋，则dp1保持不变
            // 如果偷窃当前房屋，需要看上一个房屋是否偷窃过
            // 如果上一个房屋没偷窃，那么dp1 = dp0 + nums[i]
            // 如果上一个房屋偷窃过，那么dp1 = dp1 + nums[i]，但要确保不超过只偷当前房屋的情况
            dp1 = max(temp + nums[i], dp1);
        }

        // 返回dp0和dp1中的较大值，作为最终的答案
        return max(dp0, dp1);
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {2, 7, 9, 3, 1};
    vector<int> v3 = {12, 1, 9, 25, 12, 11};
    cout << s.rob(v1) << endl;
    cout << s.rob(v2) << endl;
    cout << s.rob(v3) << endl;
    return 0;
}