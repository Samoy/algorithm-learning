#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.cn/problems/candy/solutions/17847/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/?envType=study-plan-v2&envId=selected-coding-interview
    int candy(vector<int> &ratings) {
        // 初始化向量，表示从左侧开始分配糖果，每个孩子至少1个
        vector<int> left(ratings.size(), 1);

        // 从左到右遍历，如果当前孩子评分大于前一个孩子，增加糖果数
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // 初始化糖果总数，等于数组末尾孩子的糖果数
        int count = left[ratings.size() - 1];

        // 从右到左遍历，如果当前孩子评分大于后一个孩子，增加糖果数
        // 并更新总糖果数，取当前孩子左右两侧糖果数的最大值
        vector<int> right(ratings.size(), 1);  // 初始化向量，表示从右侧开始分配糖果，每个孩子至少1个
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
            count += max(left[i], right[i]);  // 更新总糖果数
        }

        // 返回总糖果数
        return count;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1{1, 0, 2};
    vector<int> v2{1, 2, 2};
    vector<int> v3{1, 2, 4, 2};
    vector<int> v4{2, 1, 3, 2};
    vector<int> v5{1, 3, 2, 2, 1};
    cout << s.candy(v1) << endl;
    cout << s.candy(v2) << endl;
    cout << s.candy(v3) << endl;
    cout << s.candy(v4) << endl;
    cout << s.candy(v5) << endl;
    return 0;
}