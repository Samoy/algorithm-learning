#include <iostream>
#include "../include/node.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // 由于`==`运算符的左结合特性，因此不能写成if (i == j == 0)
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if (j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
                else grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[row - 1][col - 1];
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<vector<int>> v1 = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    cout << s.minPathSum(v1) << endl;
    vector<vector<int>> v2 = {
            {1, 2, 3},
            {4, 5, 6}
    };
    cout << s.minPathSum(v2) << endl;
    return 0;
}