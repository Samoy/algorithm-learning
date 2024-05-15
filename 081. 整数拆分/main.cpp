#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // https://leetcode.cn/problems/integer-break/solutions/352875/zheng-shu-chai-fen-by-leetcode-solution/?envType=study-plan-v2&envId=selected-coding-interview
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int) pow(3, quotient);
        } else if (remainder == 1) {
            return (int) pow(3, quotient - 1) * 4;
        } else {
            return (int) pow(3, quotient) * 2;
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.integerBreak(2) << endl;
    cout << s.integerBreak(8) << endl;
    cout << s.integerBreak(10) << endl;
    cout << s.integerBreak(24) << endl;
    cout << s.integerBreak(3) << endl;
    return 0;
}