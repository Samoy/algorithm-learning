#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    /*
     * 基本思想：
     * 1.长度检查：首先，通过比较 s 和 goal 的长度来确保它们能够通过旋转得到彼此，
     * 这是必要条件。如果长度不相等，直接返回 false。
     *
     * 2.旋转验证：利用字符串拼接 (goal + goal)，这个操作实质上是在不真正进行多次旋转的情况下，
     * 检查 s 是否能作为 goal 的某个旋转形式存在。因为如果 s 可以通过旋转得到 goal，
     * 那么它必然作为子串出现在连续两次的 goal 中。
     *
     * 3. 查找操作：使用 std::string::find 方法查找 s 是否为 (goal + goal) 的子串。
     * 如果 find 返回的不是 -1，说明找到了匹配，即 s 可以通过旋转变为 goal，此时返回 true；否则返回 false。
     */
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (goal + goal).find(s) != -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.rotateString("abcde", "cdeab") << endl;
    cout << s.rotateString("abcde", "abced") << endl;
    return 0;
}