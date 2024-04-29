#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
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
