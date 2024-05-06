#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3)return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0)break;
            if (k > 0 && nums[k] == nums[k - 1])continue;
            int i = k + 1, j = static_cast<int>(nums.size()) - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < 0) {
                    i++;
                    while (i < j && nums[i] == nums[i - 1])i++;
                } else if (sum > 0) {
                    j--;
                    while (i < j && nums[j] == nums[j + 1])j--;
                } else {
                    res.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                    while (i < j && nums[i] == nums[i - 1])i++;
                    while (i < j && nums[j] == nums[j + 1])j--;
                }
            }
        }
        return res;
    }
};

void print2DVector(const std::vector<std::vector<int>> &vec2d) {
    cout << "[";
    for (const auto &row: vec2d) {
        cout << "[";
        for (const auto &elem: row) {
            std::cout << elem << ',';
        }
        std::cout << "]," << endl;
    }
    std::cout << "]" << endl;
}

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> arr1 = vector<int>{-1, 0, 1, 2, -1, -4};
    vector<int> arr2 = vector<int>{0, 1, 1};
    vector<int> arr3 = vector<int>{0, 0, 0};
    print2DVector(s.threeSum(arr1));
    print2DVector(s.threeSum(arr2));
    print2DVector(s.threeSum(arr3));
    return 0;
}