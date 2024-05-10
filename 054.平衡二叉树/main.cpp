#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {

//        if (root == nullptr)return true;
//        return abs(depth(root->left) - depth(root->right)) <= 1
//               && isBalanced(root->left)
//               && isBalanced(root->right);
        return recur(root) != -1;
    }

private:
    int depth(TreeNode *root) {
        if (root == nullptr)return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    int recur(TreeNode *root) {
        if (root == nullptr)return true;
        int left = recur(root->left);
        if (left == -1)return false;
        int right = recur(root->right);
        if (right == -1) return false;
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.isBalanced(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))) << endl;
    cout << s.isBalanced(
            new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)),
                         new TreeNode(2))) << endl;
    return 0;
}