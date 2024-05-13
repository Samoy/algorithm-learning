#include "../include/node.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // 初始化一个vector来存储丑数序列，预先分配n个元素的空间以优化性能
        vector<int> uglyNumbers;
        uglyNumbers.reserve(n);

        // 初始化三个指针，分别对应2、3、5的倍数在丑数序列中的位置
        int idx2 = 0, idx3 = 0, idx5 = 0;

        // 初始化三个变量，分别存储下一个可能的丑数（2、3、5的倍数）
        int next2 = 2, next3 = 3, next5 = 5;

        // 先将第一个丑数1加入序列
        uglyNumbers.push_back(1);

        // 循环直到找到第n个丑数
        while (uglyNumbers.size() < n) {
            // 找出三个指针对应的丑数中的最小值
            int minVal = min({next2, next3, next5});

            // 将最小值加入丑数序列
            uglyNumbers.push_back(minVal);

            // 根据选择的最小值更新相应的指针和下一个候选丑数
            // 如果最小值是2的倍数，下一个可能是2的倍数的丑数就是当前丑数乘以2
            if (next2 == minVal) {
                next2 = 2 * uglyNumbers[++idx2];
            }
            // 同理，更新3和5的倍数对应的丑数和指针
            if (next3 == minVal) {
                next3 = 3 * uglyNumbers[++idx3];
            }
            if (next5 == minVal) {
                next5 = 5 * uglyNumbers[++idx5];
            }
        }

        // 返回第n个丑数
        return uglyNumbers[n - 1];
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.nthUglyNumber(10) << endl;
    cout << s.nthUglyNumber(1) << endl;
    cout << s.nthUglyNumber(2) << endl;
    cout << s.nthUglyNumber(60) << endl;
    return 0;
}