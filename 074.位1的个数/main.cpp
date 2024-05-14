#include <iostream>

using namespace std;

class Solution {
public:
    // 常规解法
    int hammingWeight(int n) {
        int s = 0;
        while (n >= 1) {
            if (n % 2 == 1) {
                s++;
            }
            n >>= 1;
        }
        return s;
    }

    // 使用位运算
    int hammingWeight2(int n) {
        int s = 0;
        while (n) {
            n &= n - 1;
            s++;
        }
        return s;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.hammingWeight(11) << endl;
    cout << s.hammingWeight(128) << endl;
    cout << s.hammingWeight(2147483645) << endl;
    cout << s.hammingWeight2(11) << endl;
    cout << s.hammingWeight2(128) << endl;
    cout << s.hammingWeight2(2147483645) << endl;
    return 0;
}