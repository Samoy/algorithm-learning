#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * @brief 找到序列中的第 n 位数字
     * @param n 序列中的位置，从 1 开始
     * @return 第 n 位的数字
     *
     * 算法步骤：
     * 1. 初始化 d（当前位数的位数）为 1，count（当前位数的总数量）为 9。
     * 2. 当 n 大于当前位数的总数量时，更新 n 并增加 d，同时 count 乘以 10。
     * 3. 计算 n 对应的索引 index。
     * 4. 确定开始数字 start，等于 10^(d-1)。
     * 5. 计算具体数字 num，等于 start 加上 index 除以 d 的结果。
     * 6. 计算在 num 内部的位数索引 digitIndex。
     * 7. 计算第 n 位数字，通过 num 除以相应的幂次再取模得到。
     * 8. 返回计算得到的第 n 位数字。
     */
    int findNthDigit(int n) {
        int d = 1, count = 9; // 初始化 d 和 count
        while (n > (long) d * count) { // 找到 n 所在的位数范围
            n -= d * count;
            d++;
            count *= 10;
        }
        int index = n - 1; // n 对应的索引
        int start = (int) pow(10, d - 1); // 当前位数的起始数字
        int num = start + index / d; // 具体数字
        int digitIndex = index % d; // 在 num 内部的位数索引
        int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10; // 第 n 位数字
        return digit;
    }
};



int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.findNthDigit(3) << endl;
    cout << s.findNthDigit(11) << endl;
    cout << s.findNthDigit(4) << endl;
    cout << s.findNthDigit(50) << endl;
    cout << s.findNthDigit(100000000) << endl;
    return 0;
}