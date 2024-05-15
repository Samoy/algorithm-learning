#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        // 假设一个数字出现的次数多于n/2，那么当排序之后，在n/2下标处肯定是这个元素
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    // 使用投票思想
    int majorityElement2(vector<int> &nums) {
        // 初始化候选众数为第一个元素，票数为0
        int candidate = nums[0], votes = 0;

        // 遍历数组
        for (int num: nums) {
            // 如果当前元素等于候选众数，票数加1
            if (num == candidate) {
                votes++;
            }
                // 如果当前元素不等于候选众数，票数减1
            else {
                // 如果票数已降为0，更新候选众数和票数
                if (votes == 0) {
                    candidate = num;
                    votes = 1;
                } else {
                    votes--;
                }
            }
        }
        // 返回候选众数
        return candidate;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1{3, 2, 3, 3};
    vector<int> v2{2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(v1) << endl;
    cout << s.majorityElement(v2) << endl;
    cout << s.majorityElement2(v1) << endl;
    cout << s.majorityElement2(v2) << endl;
    return 0;
}