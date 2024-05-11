#include <iostream>
#include "../include/node.h"

using namespace std;

void print(vector<int> vec) {
    std::cout << "[";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

class Solution {
public:
    vector<int> runningSum(const vector<int> &nums) {
        vector<int> sums{};
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                sums.push_back(nums[i]);
            } else {
                sums.push_back(sums[i - 1] + nums[i]);
            }
        }
        return sums;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    print(s.runningSum({1, 2, 3, 4}));
    print(s.runningSum({1, 1, 1, 1}));
    print(s.runningSum({3, 1, 2, 10, 1}));
    return 0;
}