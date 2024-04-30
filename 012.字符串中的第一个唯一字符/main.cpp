#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (map.count(ch)) {
                map[ch]++;
            } else {
                map[ch] = 0;
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.firstUniqChar("leetcode") << endl;
    cout << s.firstUniqChar("loveleetcode") << endl;
    cout << s.firstUniqChar("aabb") << endl;
    return 0;
}