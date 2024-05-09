#include <iostream>
#include <vector>
#include "../include/node.h"
#include <algorithm>

using namespace std;

class Solution {
private:
    int quickSelect(vector<int> &nums, int k) {
        // 随机选择基准数
        int pivot = nums[rand() % nums.size()];
        vector<int> big, equal, small;
        for (int num: nums) {
            if (num > pivot) {
                big.push_back(num);
            } else if (num < pivot) {
                small.push_back(num);
            } else {
                equal.push_back(num);
            }
        }
        // 第k大元素在big中，递归划分
        if (k <= big.size())return quickSelect(big, k);
        // 第k大元素在small中，递归划分
        if (nums.size() - small.size() < k)
            return quickSelect(small, k - nums.size() + small.size());
        return pivot;
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, k);
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1 = {3, 2, 1, 5, 6, 4};
    vector<int> v2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(v1, 2) << endl;
    cout << s.findKthLargest(v2, 4) << endl;
    return 0;
}