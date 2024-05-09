#include <iostream>
#include <vector>
#include "../include/node.h"
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // 参考：https://leetcode.cn/problems/course-schedule/solutions/250377/bao-mu-shi-ti-jie-shou-ba-shou-da-tong-tuo-bu-pai-
        // 定义入度数组
        vector<int> inDegree(numCourses, 0);
        // 定义邻接表，我们使用map进行储存
        unordered_map<int, vector<int>> adjList;
        for (vector<int> v: prerequisites) {
            inDegree[v[0]]++;
            if (adjList.count(v[1])) {
                // 如果当前课存在于邻接表，则添加后续课程中
                adjList[v[1]].push_back(v[0]);
            } else {
                // 当前课不存在于邻接表
                adjList[v[1]] = {v[0]};
            }
        }
        // 定义队列，队列中始终保存入度为0的课程
        queue<int> q;
        // 填充队列
        for (int i = 0; i < inDegree.size(); ++i) {// 所有入度为0的课程入列
            if (inDegree[i] == 0)q.push(i); // 这些课程可以直接学习
        }
        int count = 0;
        while (!q.empty()) {
            // 当前课程学习完毕，出列
            int cur = q.front();
            q.pop();
            // 课程数量+1
            count++;
            // 获取这门课对应的后续课
            auto toEnQueue = adjList[cur];
            if (!toEnQueue.empty()) {
                for (int i: toEnQueue) {
                    // 学习后续课程，入度减1
                    inDegree[i]--;
                    // 如果入度为0，则入列
                    if (inDegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        // 直到所有的课程都学习完毕，则返回true。
        return count == numCourses;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<vector<int>> v1 = {
            {1, 0}
    };
    vector<vector<int>> v2 = {
            {1, 0},
            {0, 1}
    };
    vector<vector<int>> v3 = {
            {0,  10},
            {3,  18},
            {5,  5},
            {6,  11},
            {11, 14},
            {13, 1},
            {15, 1},
            {17, 4}
    };
    vector<vector<int>> v4 = {
            {1, 0},
            {0, 3},
            {0, 2},
            {3, 2},
            {2, 5},
            {4, 5},
            {5, 6},
            {2, 4}
    };
//    cout << s.canFinish(2, v1) << endl;
//    cout << s.canFinish(2, v2) << endl;
    cout << s.canFinish(20, v3) << endl;
    cout << s.canFinish(7, v4) << endl;
    return 0;
}