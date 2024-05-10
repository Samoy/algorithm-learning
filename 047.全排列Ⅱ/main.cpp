#include <iostream>
#include <vector>
#include "../include/node.h"
#include <numeric>
#include <unordered_map>
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
private:
    vector<vector<int>> res;

    void backtrack(vector<int> nums, int x) {
        if (x == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        set<int> st;
        for (int i = x; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                continue;
            }
            st.insert(nums[i]);
            swap(nums[i], nums[x]);
            backtrack(nums, x + 1);
            swap(nums[i], nums[x]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // 继续使用回溯法
        backtrack(nums, 0);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> nums{1, 1, 2};
    print2DVector(s.permuteUnique(nums));
    return 0;
}