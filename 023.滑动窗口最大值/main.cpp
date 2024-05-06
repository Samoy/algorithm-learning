#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int> &nums, int k) {
        deque<int> deq; // 单调递减队列
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            // 维护队列的单调性
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);

            // 当队首元素超出窗口范围时，将其移除
            if (i >= k - 1) {
                res.push_back(nums[deq.front()]);
                if (deq.front() == i - k + 1) {
                    deq.pop_front();
                }
            }
        }
        return res;
    }
};


void print(const vector<int> &vec) {
    std::cout << "[";
    for (int i: vec) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> arr1 = vector<int>{1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> arr2 = vector<int>{1};
    print(s.maxSlidingWindow(arr1, 3));
    print(s.maxSlidingWindow(arr2, 1));
    return 0;
}