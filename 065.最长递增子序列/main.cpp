#include "../include/node.h"
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        vector<int> tails; // 递增子序列的尾巴列表，初始为空
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // 使用二分查找找到新元素可以插入的位置
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);

            if (it == tails.end()) {
                // 如果找不到插入位置，将新元素追加到尾巴列表末尾
                tails.push_back(nums[i]);
            } else {
                // 如果找到插入位置，替换当前位置的元素，使得尾巴列表保持递增
                *it = nums[i];
            }
        }

        // 返回尾巴列表的长度，即最长递增子序列的长度
        return tails.size();
    }
};



int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> v2 = {0, 1, 0, 3, 2, 3};
    vector<int> v3 = {7, 7, 7, 7, 7, 7, 7};
    vector<int> v4 = {11, 12, 13, 14, 15, 6, 7, 8, 101, 18};
    cout << s.lengthOfLIS(v1) << endl;
    cout << s.lengthOfLIS(v2) << endl;
    cout << s.lengthOfLIS(v3) << endl;
    cout << s.lengthOfLIS(v4) << endl;
    return 0;
}