#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

private:
    string covert(const string &s) {
        unordered_map<char, char> map;
        string res;
        int index = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (!map.count(ch)) {
                index++;
                map[ch] = static_cast<char>(index + '0');
            }
            res += static_cast<char>(map[ch]);
        }
        return res;
    }

public:
    // 官方解法：
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.length(); ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    };

    // 自己摸索的解法
    bool myIsIsomorphic(string s, string t) {
        return covert(s) == covert(t);
    };
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.isIsomorphic("egg", "add") << endl; // true
    cout << s.isIsomorphic("foo", "bar") << endl; // false
    cout << s.isIsomorphic("paper", "title") << endl; // true
    cout << s.isIsomorphic("a", "a") << endl; // true
    cout << s.isIsomorphic("badc", "baba") << endl; // false
    cout << s.isIsomorphic("aaeaa", "uuxyy") << endl; // false
    return 0;
}