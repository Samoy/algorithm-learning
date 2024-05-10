#include <iostream>
#include <vector>
#include "../include/node.h"
#include <algorithm>

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
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
            if (i > start && nums[i] == nums[i - 1]) continue;
            if (tar - nums[i] < 0)break;
            v.push_back(nums[i]);
            // 进行下一次遍历
            backtrack(v, nums, i + 1, tar - nums[i], res);
            v.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> candidates1{10, 1, 2, 7, 6, 1, 5};
    print2DVector(s.combinationSum2(candidates1, 8));
    vector<int> candidates2{2, 5, 2, 1, 2};
    print2DVector(s.combinationSum2(candidates2, 5));
    return 0;
}