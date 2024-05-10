#include <iostream>
#include <vector>
#include "../include/node.h"
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

void print2DVector(const std::vector<std::vector<int>> &vec2d) {
    cout << "[";
    for (const auto &row: vec2d) {
        cout << "[";
        for (const auto &elem: row) {
            std::cout << elem << ',';
        }
        std::cout << "]," << endl;
    }
    std::cout << "]" << endl;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        backtrack(v, candidates, 0, target, res);
        return res;
    }

private:

    void backtrack(vector<int> v, vector<int> &nums, int start, int tar, vector<vector<int>> &res) {
        if (tar == 0) {
            res.push_back(v);
            v.clear();
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            // 若子集和超过 target ，则直接结束循环
            // 这是因为数组已排序，后边元素更大，子集和一定超过 target
            if (tar - nums[i] < 0) {
                break;
            }
            // 尝试进行选择
            v.push_back(nums[i]);
            // 进行下一轮选择
            backtrack(v, nums, i, tar - nums[i], res);
            // 回溯
            v.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> candidates1{2, 3, 6, 7};
    print2DVector(s.combinationSum(candidates1, 7));
    vector<int> candidates2{2, 3, 5};
    print2DVector(s.combinationSum(candidates2, 8));
    return 0;
}