#include "../include/node.h"
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        // 如果数组为空，则返回0，因为空数组没有子数组和
        if (nums.empty()) return 0;
        // 初始化当前子数组和以及全局最大子数组和为数组的第一个元素
        int current_sum = nums[0], max_sum = nums[0];
        // 从数组的第二个元素开始遍历
        for (int i = 1; i < nums.size(); ++i) {
            // 更新当前子数组和：如果当前元素加上前一个子数组和比当前元素本身小，则抛弃前一个子数组，重新开始计算子数组和
            current_sum = max(nums[i], current_sum + nums[i]);
            // 更新全局最大子数组和：如果当前子数组和大于已知的最大子数组和，则更新最大值
            max_sum = max(max_sum, current_sum);
        }
        // 返回最大子数组和
        return max_sum;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2 = {1};
    vector<int> v3 = {5, 4, -1, 7, 8};
    cout << s.maxSubArray(v1) << endl;
    cout << s.maxSubArray(v2) << endl;
    cout << s.maxSubArray(v3) << endl;
    return 0;
}