#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode *> que;
        que.push(root);
        bool orderLeft = true;
        // 使用双端队列解决
        while (!que.empty()) {
            deque<int> levelList;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();
                if (orderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            orderLeft = !orderLeft;
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    print2DVector(s.zigzagLevelOrder(tree));
    return 0;
}