#include <iostream>
#include <vector>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 使用递归解决
        if (root == nullptr || root == p || root == q)return root;
        TreeNode *left_lca = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);
        // 如果p和q分别在左子树和右子树中，根节点就是LCA
        if (left_lca != nullptr && right_lca != nullptr) {
            return root;
        }
        // 如果p或q在当前节点的左子树中，返回左子树的LCA
        if (left_lca != nullptr) {
            return left_lca;
        }
        // 否则，p或q在当前节点的右子树中，返回右子树的LCA
        return right_lca;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *left = new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)));
    TreeNode *right = new TreeNode(1, new TreeNode(0), new TreeNode(8));
    TreeNode *root = new TreeNode(3, left, right);
    TreeNode *node = s.lowestCommonAncestor(root, left, right);
    cout << node->val << endl;
    delete left;
    delete right;
    delete root;
    delete node;
    return 0;
}