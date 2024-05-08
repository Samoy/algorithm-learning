#include <iostream>
#include <vector>
#include "../include/node.h"

using namespace std;

class Solution {
private:
    // 定义两个私有成员变量，res用于存储找到的结果，k用于存储要找的第k个最小元素
    int res, k;

    // 定义深度优先搜索（DFS）辅助函数，用于遍历BST
    void dfs(TreeNode *node) {
        // 如果当前节点为空，则直接返回
        if (node == nullptr)return;

        // 先递归遍历左子树（BST中左子树的元素都小于当前节点）
        dfs(node->left);

        // 如果已经找到k个元素（k减到0），则提前结束后续遍历
        if (k == 0)return;

        // 每访问一个节点，k减1，当k减到0时，当前节点就是要找的第k个最小元素
        if (--k == 0)res = node->val;

        // 继续递归遍历右子树（BST中右子树的元素都大于当前节点）
        dfs(node->right);
    }

public:
    // 主函数，接收BST的根节点和整数k作为输入，返回第k个最小元素
    int kthSmallest(TreeNode *root, int k) {
        // 把输入的k赋值给类成员变量k
        this->k = k;

        // 调用dfs函数开始遍历
        dfs(root);

        // 返回找到的结果
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *root1 = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    TreeNode *root2 = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)),
                                   new TreeNode(6));
    cout << s.kthSmallest(root1, 1) << endl;
    cout << s.kthSmallest(root2, 3) << endl;
    return 0;
}