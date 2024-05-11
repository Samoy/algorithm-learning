#include <iostream>
#include "../include/node.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 如果先序遍历为空，说明没有节点，返回空指针
        if (preorder.empty()) return nullptr;

        // 获取根节点的值，即先序遍历的第一个元素
        int root_value = preorder[0];

        // 在中序遍历中找到根节点的索引位置
        int in_root_pos = find(inorder.begin(), inorder.end(), root_value) - inorder.begin();

        // 创建根节点
        TreeNode *root = new TreeNode(root_value);

        // 递归构建左子树
        // 使用迭代器范围初始化一个新的向量，表示先序遍历中根节点左侧的子序列
        // 同样，为中序遍历创建对应子序列
        vector<int> pre_left(preorder.begin() + 1, preorder.begin() + 1 + in_root_pos);
        vector<int> in_left(inorder.begin(), inorder.begin() + in_root_pos);
        root->left = buildTree(pre_left, in_left);

        // 递归构建右子树
        // 使用迭代器范围初始化新的向量，表示先序遍历中根节点右侧的子序列
        // 同样，为中序遍历创建对应子序列
        vector<int> pre_right(preorder.begin() + 1 + in_root_pos, preorder.end());
        vector<int> in_right(inorder.begin() + in_root_pos + 1, inorder.end());
        root->right = buildTree(pre_right, in_right);

        // 返回根节点
        return root;
    }

};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *tree1 = s.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
    cout << tree1->val << endl;
    delete tree1;  // 释放内存

    TreeNode *tree2 = s.buildTree({-1}, {-1});
    cout << tree2->val << endl;
    delete tree2;  // 释放内存
    return 0;
}