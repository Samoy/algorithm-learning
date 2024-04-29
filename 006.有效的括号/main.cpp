#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sk{};
        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                sk.push(ch);
            }
            else
            {
                if (sk.empty() || (ch == ')' && sk.top() != '(') ||
                    (ch == '}' && sk.top() != '{') ||
                    (ch == ']' && sk.top() != '['))
                {
                    return false;
                }
                sk.pop();
            }
        }
        return sk.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s{};
    cout << s.isValid("{}[]") << endl; // true
    cout << s.isValid("{()}") << endl; // true
    cout << s.isValid("{]") << endl;   // false
    cout << s.isValid("{[}]") << endl; // false
    cout << s.isValid("]") << endl;    // false
    cout << s.isValid("(])") << endl;  // true
    return 0;
}
