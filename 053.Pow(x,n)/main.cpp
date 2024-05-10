#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // 先处理特殊情况
        // 当x为0时，根据n的正负返回0或INT_MAX（表示无穷大）
        if (x == 0) {
            return n >= 0 ? 0 : INT_MAX;
        }
        // 当n为0时，返回1，因为任何数的0次方都是1
        if (n == 0) return 1;
        // 当x为1时，直接返回x，因为任何数的1次方都是它本身
        if (x == 1) return x;

        // 判断n是否为负数，如果是，则标记为负，并转换n为正数
        bool negative = n < 0;
        n = abs(n);
        // 处理边界溢出情况
        if (n == INT_MIN) {
            return negative ? 1 / myPow(x, INT_MAX) : myPow(x, INT_MAX);
        }
        /**************使用递归****************/
        return powHelper(x, n, 1, negative);
        /**************使用迭代****************/
        // 初始化累乘因子为1，用于计算x的n次方
        double multi = 1;

        // 使用循环进行指数运算，每次将x自乘，n右移一位
        while (n > 0) {
            // 检查n是否为奇数，如果是，则将x乘入累乘因子multi
            // 举个例子 2^3 = 2^2 * 2，也就是说奇数我们可以这么理解：
            // 奇数时= (奇数-1)*奇数
            if (n % 2 != 0) {
                multi *= x;
            }
            // 累乘：将x自乘，模拟指数运算的每一次乘法
            x *= x;
            // 右移：将n的二进制表示向右移动一位，相当于n除以2并向下取整
            n >>= 1;
        }

        // 根据n是否为负数，返回1/multi（x的负n次方）或multi（x的正n次方）
        return negative ? 1 / multi : multi;
    }

private:
    // 定义一个私有辅助函数powHelper，用于递归计算x的n次方
    // 参数：
    // x: 底数
    // n: 指数（已转换为正数或0）
    // acc: 递归过程中累积的乘积，初始为1
    // negative: 标记n是否为负数
    double powHelper(double x, int n, double acc, bool negative) {
        // 当n为0时，根据n是否为负数返回1/acc或acc
        if (n == 0) {
            return negative ? 1 / acc : acc;
        }

        // 如果n是奇数（n % 2 == 1），则将x乘入累乘因子acc，并将n减半
        // 然后继续递归计算x的(n/2)次方
        if (n % 2 == 1) {
            return powHelper(x * x, n >> 1, x * acc, negative);
        }

        // 如果n是偶数，不将x乘入累乘因子acc，而是将n减半
        // 继续递归计算x的(n/2)次方
        // 注意：这里不需要x * acc，因为偶数次幂已经在下一次递归中处理
        return powHelper(x * x, n >> 1, acc, negative);
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.myPow(2.00000, 10) << endl;
    cout << s.myPow(2.10000, 3) << endl;
    cout << s.myPow(2.00000, -2) << endl;
    cout << s.myPow(0.00001, 2147483647) << endl;
    cout << s.myPow(2.00000, INT_MIN) << endl;
    return 0;
}