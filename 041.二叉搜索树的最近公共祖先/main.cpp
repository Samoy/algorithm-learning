#include <iostream>
#include <vector>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 如果root.val小于p.val并且小于q.val，说明p,q在root的右子树中
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // 如果root.val大于p.val并且大于q.val，说明p,q在root的左子树中
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *p = new TreeNode(2, 0, new TreeNode(4, new TreeNode(3), new TreeNode(5)));
    TreeNode *q = new TreeNode(8, new TreeNode(7), new TreeNode(9));
    TreeNode *root = new TreeNode(6, p,
                                  q);
    cout << s.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}