#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *t1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << s.maxDepth(t1) << endl;
    TreeNode *t2 = new TreeNode(1, nullptr, new TreeNode(2));
    cout << s.maxDepth(t2) << endl;
    return 0;
}