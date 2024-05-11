#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1)return 1;
        return fib(n - 2) + fib(n - 1);
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.fib(2) << endl;
    cout << s.fib(3) << endl;
    cout << s.fib(4) << endl;
    return 0;
}