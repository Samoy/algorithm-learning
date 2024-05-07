#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // https://leetcode.cn/problems/rotate-image/?envType=study-plan-v2&envId=selected-coding-interviewhttps://leetcode.cn/problems/rotate-image/?envType=study-plan-v2&envId=selected-coding-interview
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

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

using Matrix = vector<vector<int>>;

int main(int argc, char const *argv[]) {
    Matrix matrix1 = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    Matrix matrix2 = {{5,  1,  9,  11},
                      {2,  4,  8,  10},
                      {13, 3,  6,  7},
                      {15, 14, 12, 16}};
    Solution s{};
    s.rotate(matrix1);
    print2DVector(matrix1);
    s.rotate(matrix2);
    print2DVector(matrix2);
    return 0;
}