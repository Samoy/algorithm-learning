#include <iostream>
#include "../include/node.h"

using namespace std;
using Matrix = vector<vector<int>>;

class Solution {
public:
    /*
     * 这个问题可以使用“折半搜索”的思想来解决。由于矩阵的行和列都是有序的，你可以从矩阵的右上角开始搜索。这里是一个简单的算法步骤：
     * 1. 初始化两个指针，`row`指向矩阵的第一行，`col`指向矩阵的最后一列。
     * 2. 当`row`小于等于矩阵的行数且`col`大于等于0时，执行以下操作：
     * - 如果`matrix[row][col]`等于`target`，找到了目标值，返回`true`。
     * - 如果`matrix[row][col]`大于`target`，说明目标值在当前元素的左方，所以将`col`减1。
     * - 如果`matrix[row][col]`小于`target`，说明目标值在当前元素的下方，所以将`row`加1。
     * 3. 如果遍历完没有找到目标值，返回`false`。
     */
    bool searchMatrix(const vector<vector<int>> &matrix, int target) {
        int p_row = 0;
        int p_col = matrix[0].size() - 1;
        while (p_row <= matrix.size() - 1 && p_col >= 0) {
            int num = matrix[p_row][p_col];
            if (num == target)return true;
            else if (num > target) p_col--;
            else if (num < target) p_row++;
        }
        return false;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    Matrix m = {{1,  4,  7,  11, 15},
                {2,  5,  8,  12, 19},
                {3,  6,  9,  16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30}
    };
    cout << s.searchMatrix(m, 5) << endl;
    cout << s.searchMatrix(m, 20) << endl;;
    cout << s.searchMatrix({{-5}}, -10) << endl;
    cout << s.searchMatrix({{1, 1}}, 2) << endl;
    return 0;
}