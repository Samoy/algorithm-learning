#include <iostream>

using namespace std;

class Solution {
public:
    // https://leetcode.cn/problems/number-of-digit-one/solutions/932573/shu-zi-1-de-ge-shu-by-leetcode-solution-zopq/?envType=study-plan-v2&envId=selected-coding-interview
    int countDigitOne(int n) {
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.countDigitOne(1) << endl;
    cout << s.countDigitOne(2) << endl;
    cout << s.countDigitOne(3) << endl;
    cout << s.countDigitOne(0) << endl;
    cout << s.countDigitOne(13) << endl;
    return 0;
}