#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    int maxProfit(const vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
    cout << s.maxProfit({7, 6, 4, 3, 1}) << endl;;
    return 0;
}