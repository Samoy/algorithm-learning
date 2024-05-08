#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    vector<int> v1 = {-1, 0, 3, 5, 9, 12};
    cout << s.search(v1, 9) << endl;
    cout << s.search(v1, 2) << endl;
    vector<int> v2 = {-1, 0, 3, 5, 9, 12, 15};
    cout << s.search(v2, 9) << endl;
    cout << s.search(v2, 2) << endl;
    vector<int> v3 = {5};
    cout << s.search(v3, -5) << endl;
    return 0;
}