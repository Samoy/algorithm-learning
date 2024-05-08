#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMin(const vector<int> &nums) {
        // return *min_element(nums.begin(), nums.end());
        // 使用二分查找
        int left = 0, right = nums.size() - 1;
        if (right == 0)return nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return nums[left];
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.findMin({1, 3, 5}) << endl;
    cout << s.findMin({2, 2, 2, 0, 1}) << endl;
    cout << s.findMin({3, 3, 3, 3, 3}) << endl;
    cout << s.findMin({1, 3, 4, 1}) << endl;
    return 0;
}