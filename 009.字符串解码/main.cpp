#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
private:
    pair<string, int> solve(const string &s, int i)
    {
        int multi = 0;
        string ans = "";
        while (i < s.length())
        {
            if (isdigit(s[i]))
            {
                multi = multi * 10 + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                auto sub_ans = solve(s, i + 1);
                i = sub_ans.second;
                while (multi > 0)
                {
                    ans += sub_ans.first;
                    multi--;
                }
            }
            else if (s[i] == ']')
            {
                return pair<string, int>(ans, i);
            }
            else
            {
                ans += s[i];
            }
            i++;
        }
        return pair<string, int>(ans, i);
    }

public:
    string decodeString(string s)
    {
        return solve(s, 0).first;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;     // "aaabcbc"
    cout << s.decodeString("3[a2[c]]") << endl;      // "accaccacc"
    cout << s.decodeString("2[abc]3[cd]ef") << endl; // "abcabccdcdcdef"
    return 0;
}
