#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int len = 0;
        for (char c: s) {
            ++map[c];
        }
        bool hasOdd = false;
        for (auto v: map) {
            int num = v.second;
            len += num;
            if (num % 2 != 0) {
                len--;
                hasOdd = true;
            }
        }
        if (hasOdd) {
            len++;
        }
        return len;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.longestPalindrome("abccccdd") << endl; // 7
    cout << s.longestPalindrome("a") << endl; // 1
    cout << s.longestPalindrome("aaaaaccc") << endl; // 7
    return 0;
}