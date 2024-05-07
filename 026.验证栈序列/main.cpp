#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    // https://leetcode.cn/problems/validate-stack-sequences/solutions/2362056/946-yan-zheng-zhan-xu-lie-mo-ni-qing-xi-wpxi6/?envType=study-plan-v2&envId=selected-coding-interview
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> sk;
        int i = 0;
        for (int num: pushed) {
            sk.push(num);
            while (!sk.empty() && sk.top() == popped[i]) {
                sk.pop();
                i++;
            }
        }
        return sk.empty();
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> pushed1 = vector<int>{1, 2, 3, 4, 5};
    vector<int> popped1 = vector<int>{4, 5, 3, 2, 1};
    cout << s.validateStackSequences(pushed1, popped1) << endl;
    vector<int> pushed2 = vector<int>{1, 2, 3, 4, 5};
    vector<int> popped2 = vector<int>{4, 3, 5, 1, 2};
    cout << s.validateStackSequences(pushed2, popped2) << endl;
    return 0;
}