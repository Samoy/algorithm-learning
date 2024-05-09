#include <iostream>
#include <vector>
#include "../include/node.h"

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
    vector<int> path;

    // 回溯函数，用于在二叉树中寻找路径，使得路径上所有节点值之和等于targetSum
    void backtrack(TreeNode *root, int targetSum) {
        // 如果当前节点为空，结束该分支的递归
        if (root == nullptr) {
            return;
        }

        // 将当前节点的值添加到路径中
        path.push_back(root->val);

        // 更新剩余的目标和
        targetSum -= root->val;

        // 如果目标和为0，且当前节点为叶子节点（无左右子节点），说明找到了一条有效路径
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            // 将找到的路径保存到结果列表中
            res.push_back(path);
        }

        // 递归探索当前节点的左子树
        backtrack(root->left, targetSum);

        // 递归探索当前节点的右子树
        backtrack(root->right, targetSum);

        // 由于当前路径未找到有效解，回溯：移除路径中的最后一个元素，尝试其他分支
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        // 本题使用回溯法
        backtrack(root, targetSum);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *t = new TreeNode(5,
                               new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr),
                               new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1))));
    print2DVector(s.pathSum(t, 22));
    return 0;
}