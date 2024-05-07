#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i = 0; i < s.size(); ++i) {
            char tmp = s[0];
            s += tmp;
            s.erase(s.begin());
            if (s == goal) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.rotateString("abcde", "cdeab") << endl;
    cout << s.rotateString("abcde", "abced") << endl;
    return 0;
}