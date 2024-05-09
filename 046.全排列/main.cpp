#include <iostream>
#include <vector>
#include "../include/node.h"
#include <numeric>

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
    // 回溯函数，用于生成给定数组的全排列
    void backtrack(vector<vector<int>> &res, vector<int> &nums, int start) {
        // 当start等于数组长度减1时，表示已生成一个有效排列，将其添加到结果中
        if (start == nums.size() - 1) {
            res.push_back(nums);
        }

        // 遍历从start到数组末尾的所有元素，尝试与start位置的元素交换
        for (int i = start; i < nums.size(); ++i) {
            // 交换nums[start]和nums[i]，生成新的排列
            swap(nums[start], nums[i]);

            // 递归调用回溯函数，处理下一个位置的元素
            backtrack(res, nums, start + 1);

            // 恢复原数组状态，以便于尝试其他排列
            swap(nums[start], nums[i]);
        }
    }


public:
    vector<vector<int>> permute(vector<int> &nums) {
        // 使用回溯法进行求解
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    print2DVector(s.permute({1, 2, 3}));
    print2DVector(s.permute({0, 1}));
    print2DVector(s.permute({1}));
    return 0;
}