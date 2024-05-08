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
    vector<vector<int>> levelOrder(TreeNode *root) {
        // 层序遍历的原理在于使用一个辅助的队列，根结点先入队，再将其数值存入tmp数组中
        // 再根结点出队，将其左右结点都入队，进行第二层遍历，每一次遍历的结尾标志为队列内所有已有结点都出队完成，其对应的左右结点都入队完成，每一层的遍历结果都存入tmp中，在每一层的遍历结尾将tmp的内容存入到res中去
        queue<TreeNode *> que;//设置辅助队列
        vector<vector<int>> res;//用来存储最终结果
        if (root != nullptr)que.push(root);//根结点先入队
        while (!que.empty()) {
            vector<int> tmp;//每一层遍历以前都初始化tmp
            for (int i = que.size(); i > 0; i--) {
                //这里需注意由于在for循环的执行过程中que.size()的值会进行更改，因此que.size()只能作为i的起点而不是终点
                TreeNode *p = que.front();
                que.pop();
                tmp.push_back(p->val);//在出队列的时刻进行打印，出队列的同时左右结点都入队列
                if (p->left != nullptr)que.push(p->left);
                if (p->right != nullptr)que.push(p->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    print2DVector(s.levelOrder(tree));
    return 0;
}