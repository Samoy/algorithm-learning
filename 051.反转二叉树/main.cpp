#include <iostream>
#include <vector>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *t1 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                                new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    TreeNode *t2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    cout << s.invertTree(t1) << endl;
    cout << s.invertTree(t2) << endl;
    cout << s.invertTree(nullptr) << endl;
    return 0;
}