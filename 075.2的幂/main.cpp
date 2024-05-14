#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.isPowerOfTwo(11) << endl;
    cout << s.isPowerOfTwo(128) << endl;
    cout << s.isPowerOfTwo(2147483645) << endl;
    return 0;
}