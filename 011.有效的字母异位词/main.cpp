#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.isAnagram("anagram", "nagaram") << endl;
    cout << s.isAnagram("rat", "car") << endl;
    return 0;
}