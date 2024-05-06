#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = static_cast<int>(s.size());
        for (int j = 0; j < len; ++j) {
            if (dic.find(s[j]) != dic.end()) {
                i = max(i, dic.find(s[j])->second);
            }
            dic[s[j]] = j;
            res = max(res, j - i);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}