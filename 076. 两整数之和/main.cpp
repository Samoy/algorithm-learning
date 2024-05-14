#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        // 循环条件：b不等于0，因为当b为0时，表示进位已经处理完毕，此时a就是结果
        while (b != 0) {
            // 计算进位，这里使用按位与操作（&）找到两个数中都为1的位，然后左移一位（<<1）
            // 这相当于模拟加法中每一位的进位（如果两个位都是1，那么在下一位会有一个1）
            int carry = (a & b) << 1;

            // 使用异或操作（^）来更新a，这会去除相同位上的1，保留不同位上的1
            // 因为异或操作具有交换律，所以a ^ b相当于(a + b) % 2，这相当于计算没有进位的情况
            a = a ^ b;

            // 将进位carry赋值给b，准备下一次循环
            b = carry;
        }

        // 当b为0时，a就是最终的和，返回a
        return a;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.getSum(1, 2) << endl;
    cout << s.getSum(2, 3) << endl;
    cout << s.getSum(11, 13) << endl;
    return 0;
}