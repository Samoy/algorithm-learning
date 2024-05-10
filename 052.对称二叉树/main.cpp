#include <iostream>
#include <vector>
#include "../include/node.h"
#include <queue>

using namespace std;

class Solution {
private:
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr)return false;
        return (left->val == right->val)
               && isMirror(left->right, right->left)
               && isMirror(left->left, right->right);
    }

public:
    bool isSymmetric(TreeNode *root) {
        // 使用迭代
        queue<pair<TreeNode *, TreeNode *>> que;
        que.emplace(root, root);
        while (!que.empty()) {
            TreeNode *left = que.front().first;
            TreeNode *right = que.front().second;
            que.pop();
            if (left == nullptr && right == nullptr)continue;
            if (left == nullptr || right == nullptr)return false;
            if (left->val != right->val)return false;
            que.emplace(left->left, right->right);
            que.emplace(left->right, right->left);
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *t1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                                new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    TreeNode *t2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
                                new TreeNode(2, nullptr, new TreeNode(3)));
    cout << s.isSymmetric(t1) << endl;
    cout << s.isSymmetric(t2) << endl;
    return 0;
}