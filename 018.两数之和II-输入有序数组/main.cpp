#include <iostream>
#include "../include/node.h"
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left <= right) {
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};

void print(vector<int> vec) {
    std::cout << "[";
    for (std::size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> vector1 = {2, 7, 11, 15};
    vector<int> vector2 = {2, 3, 4};
    vector<int> vector3 = {-1, 0};
    print(s.twoSum(vector1, 18));
    print(s.twoSum(vector2, 6));
    print(s.twoSum(vector3, -1));
    return 0;
}