#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string tmp;
        stack<string> sk;
        for (char c: s) {
            if (c != ' ') {
                tmp += c;
            } else {
                sk.push(tmp);
                tmp = "";
            }
        }
        if (!tmp.empty()) {
            sk.push(tmp);
        }
        string result;
        while (!sk.empty()) {
            if (!sk.top().empty()) {
                result += sk.top() + " ";
            }
            sk.pop();
        }
        result.pop_back();
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.reverseWords("the sky is blue") << endl;
    cout << s.reverseWords("  hello world  ") << endl;
    cout << s.reverseWords("a good   example") << endl;
    return 0;
}