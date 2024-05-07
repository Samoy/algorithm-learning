#include <iostream>
#include <vector>

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
    vector<vector<int>> generateMatrix(int n) {
        using Matrix = vector<vector<int>>;
        Matrix matrix = vector(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 0;
        while (true) {
            // 向右
            for (int i = left; i <= right; i++)matrix[top][i] = ++num;
            if (++top > bottom) break;
            // 向下
            for (int i = top; i <= bottom; i++)matrix[i][right] = ++num;
            if (left > --right) break;
            // 向左
            for (int i = right; i >= left; i--)matrix[bottom][i] = ++num;
            if (top > --bottom) break;
            // 向上
            for (int i = bottom; i >= top; i--)matrix[i][left] = ++num;
            if (++left > right)break;
        }
        return matrix;
    }
};


using Matrix = vector<vector<int>>;

int main(int argc, char const *argv[]) {
    Solution s{};
    print2DVector(s.generateMatrix(1));
    print2DVector(s.generateMatrix(2));
    print2DVector(s.generateMatrix(3));
    print2DVector(s.generateMatrix(4));
    return 0;
}