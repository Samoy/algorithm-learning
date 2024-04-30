#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        queue<char> que;
        // 将s的所有子字符放到队列中
        for (char c: s) {
            que.push(c);
        }
        // 遍历t
        for (char c: t) {
            // 如果遇到了队头的元素，将队头的元素pop掉
            if (c == que.front()) {
                que.pop();
            }
            // 如果队列为空，则说明肯定是子序列，没必要在进行遍历了。
            if (que.empty()) {
                break;
            }
        }
        // 最后判读队列是否为空则说明s是否是t的子序列。
        return que.empty();
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.isSubsequence("abc", "ahbgdc") << endl; // true
    cout << s.isSubsequence("axc", "ahbgdc") << endl; // false
    return 0;
}