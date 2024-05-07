#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> res;
        // 螺旋矩阵的顺序是right->bottom->left->top这样的循环方向
        while (true) {
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]); // left to right
            if (++t > b) break;
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]); // top to bottom
            if (l > --r) break;
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]); // right to left
            if (t > --b) break;
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]); // bottom to top
            if (++l > r) break;
        }
        return res;
    }
};

void print(vector<int> v) {
    cout << "[";
    for (int num: v) {
        cout << num << ", ";
    }
    cout << "]" << endl;
}

using Matrix = vector<vector<int>>;

int main(int argc, char const *argv[]) {
    Solution s{};
    Matrix matrix1 = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    print(s.spiralOrder(matrix1));
    Matrix matrix2 = {{1, 2,  3,  4},
                      {5, 6,  7,  8},
                      {9, 10, 11, 12}};
    print(s.spiralOrder(matrix2));
    return 0;
}