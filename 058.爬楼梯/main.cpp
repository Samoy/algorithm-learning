#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    // 经典动态规划问题：爬楼梯
    int climbStairs(int n) {
        // 递归解决（时间超出限制）：
        // if (n == 1)return 1;
        // if (n == 2) return 2;
        // return climbStairs(n - 1) + climbStairs(n - 2);

        // 使用动态规划解决（堆溢出）
        // vector<int> dp(n + 1);  // 动态规划数组
        // dp[1] = 1;  // 第一级：1
        // dp[2] = 2;  // 第二级: 2
        // // 从第三级开始，每级楼梯的方法数等于前两级楼梯的方法数之和
        // for (int i = 3; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];

        // 使用迭代解决
        // 初始化两个变量，a表示到达第n-1级楼梯的方法数，b表示到达第n-2级楼梯的方法数
        int a = 1, b = 1, sum;

        // 循环n-1次，因为初始已知到达第1级和第2级楼梯的方法数
        for (int i = 0; i < n - 1; ++i) {
            // 更新sum为a和b的和，即到达第i+2级楼梯的方法数
            sum = a + b;
            // 更新a为b的值，即将到达第i+1级楼梯的方法数移到a
            a = b;
            // 更新b为sum的值，即将到达第i+2级楼梯的方法数移到b
            b = sum;
        }

        // 返回b，即到达第n级楼梯的方法数
        return b;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.climbStairs(1) << endl;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(4) << endl;
    return 0;
}