#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    int maxProfit(const vector<int> &prices) {
        // 由于股票不可能在买入之前卖出，因此我们得出以下结论：
        // 首先应该找到买入点，假设买入点为第0天
        int buy = prices[0];
        // 初始化设置收益为0
        int profit = 0;
        // 从第1天开始寻找最佳买入点
        for (int i = 1; i < prices.size(); ++i) {
            // 当天价格
            int price = prices[i];
            // 前一天价格
            int previous = prices[i - 1];
            // 如果它比前一天低，说明适合作为买入点
            if (price < previous) {
                // 找到价格最低点
                buy = min(buy, price);
            } else {
                // 否则说明适合做出卖出点
                int currentDiff = price - buy;
                // 找出收益比较大的
                profit = max(currentDiff, profit);
            }
        }
        return profit;
    }

    int maxProfit2(const vector<int> &prices) {
        // 初始化最低买入价格和最大利润
        int minBuyPrice = INT_MAX, maxProfit = 0;

        // 遍历价格数组
        for (int price: prices) {
            // 如果当前价格低于最低买入价格，更新最低买入价格
            minBuyPrice = min(minBuyPrice, price);
            // 如果当前价格高于最低买入价格，更新最大利润
            maxProfit = max(maxProfit, price - minBuyPrice);
        }

        // 返回最大利润
        return maxProfit;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
    cout << s.maxProfit({7, 6, 4, 3, 1}) << endl;;
    cout << s.maxProfit2({2, 2, 2, 2, 2}) << endl;
    cout << s.maxProfit2({2, 4, 1}) << endl;
    return 0;
}