#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.cn/problems/zigzag-conversion/solutions/21610/zzi-xing-bian-huan-by-jyd/?envType=study-plan-v2&envId=selected-coding-interview
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c: s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }
        string res{};
        for (const string &row: rows)
            res += row;
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("A", 1) << endl;
    return 0;
}