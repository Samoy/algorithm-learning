#include <iostream>
#include "../include/node.h"
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Codec {
public:

    /**
     * Encodes a tree to a single string.
     *
     * @param root Pointer to the root of the binary tree to be serialized.
     * @return A string representation of the serialized binary tree.
     */
    string serialize(TreeNode *root) {
        // 使用ostringstream对象来构建序列化字符串
        ostringstream oss;
        // 用于广度优先遍历的队列
        queue<TreeNode *> que;
        // 将根节点放入队列
        que.push(root);

        // 广度优先遍历，直到队列为空
        while (!que.empty()) {
            // 取出队列前面的节点
            TreeNode *node = que.front();
            que.pop();

            // 处理空节点
            if (node == nullptr) {
                oss << "#" << " "; // 序列化空节点
            } else {
                // 序列化非空节点的值
                oss << node->val << " ";
                // 将非空节点的左右子节点放入队列
                que.push(node->left);
                que.push(node->right);
            }
        }

        // 返回序列化后的字符串
        return oss.str();
    }

    /**
     * Decodes your encoded data to tree.
     *
     * @param data The serialized string representation of a binary tree.
     * @return Pointer to the root of the deserialized binary tree.
     */
    TreeNode *deserialize(string data) {
        // 使用istringstream对象来解析输入的字符串
        istringstream iss(data);
        // 用于构建二叉树的队列
        queue<TreeNode *> que;
        // 用于存储当前读取到的节点值
        string val;

        // 读取根节点
        getline(iss, val, ' ');
        if (val == "#")return nullptr; // 如果根节点为空，则直接返回nullptr
        // 创建根节点
        TreeNode *root = new TreeNode(stoi(val));
        // 将根节点放入队列
        que.push(root);

        // 解析剩余的节点，直到队列为空
        while (!que.empty()) {
            // 取出队列前面的节点
            TreeNode *node = que.front();
            que.pop();

            // 读取左子节点
            getline(iss, val, ' ');
            if (val == "#") {
                node->left = nullptr;
            } else {
                // 创建左子节点并将其放入队列
                node->left = new TreeNode(stoi(val));
                que.push(node->left);
            }

            // 读取右子节点
            getline(iss, val, ' ');
            if (val == "#") {
                node->right = nullptr;
            } else {
                // 创建右子节点并将其放入队列
                node->right = new TreeNode(stoi(val));
                que.push(node->right);
            }
        }

        // 返回根节点
        return root;
    }
};


int main(int argc, char const *argv[]) {
    Codec c{};
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)));
    cout << c.deserialize(c.serialize(root))->val << endl;
    return 0;
}