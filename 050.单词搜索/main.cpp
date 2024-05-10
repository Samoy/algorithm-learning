#include <iostream>
#include <vector>
#include "../include/node.h"
#include <algorithm>
#include <queue>

using namespace std;
using Matrix = vector<vector<char>>;

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
    bool exist(Matrix &board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (backtrack(board, word, i, j, 0))return true;
            }
        }
        return false;
    }

private:
    int rows, cols;

    bool backtrack(Matrix &board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res =
                // 向下
                backtrack(board, word, i + 1, j, k + 1)
                // 向上
                || backtrack(board, word, i - 1, j, k + 1)
                // 向右
                || backtrack(board, word, i, j + 1, k + 1)
                // 向左
                || backtrack(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    Matrix m1 = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    Matrix m2 = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    Matrix m3 = {{'A', 'B', 'C', 'E'},
                 {'S', 'F', 'C', 'S'},
                 {'A', 'D', 'E', 'E'}
    };
    cout << s.exist(m1, "ABCCED") << endl;
    cout << s.exist(m2, "SEE") << endl;
    cout << s.exist(m3, "ABCB") << endl;
    return 0;
}