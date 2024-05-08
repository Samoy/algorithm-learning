#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int pivotIndex(const vector<int> &nums) {
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            rightSum -= nums[i];
            if (rightSum == leftSum)return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.pivotIndex({1, 7, 3, 6, 5, 6}) << endl;
    cout << s.pivotIndex({1, 2, 3}) << endl;
    cout << s.pivotIndex({2, 1, -1}) << endl;
    cout << s.pivotIndex({-1, -1, 0, 1, 1, -1}) << endl;
    return 0;
}