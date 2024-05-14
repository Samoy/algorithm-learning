#include <iostream>
#include "../include/node.h"

using namespace std;
using Matrix = vector<vector<int>>;

class Solution {
public:
    // 使用双指针解决，不断的移动首尾指针
    int maxArea(const vector<int> &height) {
        // 初始化指针，一个指向数组的开始，一个指向数组的结束
        int p_start = 0;
        int p_end = height.size() - 1;
        // 初始化最大面积为0
        int max_area = 0;
        while (p_start <= p_end) {
            // 计算当前矩形的面积，取较小的高度乘以宽度
            int width = p_end - p_start;
            int minHeight = min(height[p_start], height[p_end]);
            // 更新最大面积
            max_area = max(max_area, width * minHeight);
            // 如果左边的高度较小，向右移动左指针，否则向左移动右指针
            // 这样可以保证在每次迭代中，较短的边总会增加
            if (height[p_start] <= height[p_end]) {
                p_start++;
            } else {
                p_end--;
            }
        }
        return max_area;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.maxArea({1, 2, 3, 2}) << endl;
    cout << s.maxArea({1, 10, 6, 2, 5, 4, 10, 3, 7}) << endl;
    cout << s.maxArea({1, 1}) << endl;
    return 0;
}