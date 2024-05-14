#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/?envType=study-plan-v2&envId=selected-coding-interview
    int maxChunksToSorted(vector<int> &arr) {
        stack<int> sk;
        for (int num: arr) {
            if (!sk.empty() && num < sk.top()) {
                int head = sk.top();
                sk.pop();
                while (!sk.empty() && num < sk.top())sk.pop();
                sk.push(head);
            } else {
                sk.push(num);
            }
        }
        return sk.size();
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1{5, 4, 3, 2, 1};
    vector<int> v2{2, 1, 3, 4, 4};
    cout << s.maxChunksToSorted(v1) << endl;
    cout << s.maxChunksToSorted(v2) << endl;
    return 0;
}