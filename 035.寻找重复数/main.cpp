#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findDuplicate(const vector<int> &nums) {
        /*
        unordered_map<int, int> map;
        for (int num: nums) {
            if (map.count(num)) {
                return num;
            } else {
                map[num] = 1;
            }
        }
        return -1;
        */
        // 上述解法无法满足题干的O(1)的空间复杂度，因此使用以下解法
        // 1.初始化两个指针slow和fast，slow指向数组的第一个元素，fast指向数组中slow指向的元素。
        // 2.在while循环中，slow每次移动一个位置，fast每次移动两个位置。如果数组中存在重复的整数，
        //    slow和fast最终会在重复的整数处相遇。
        // 3. 当slow和fast相遇后，为了找到这个重复的整数，我们再从数组的起始位置开始用一个新指针slow，
        //    让它每次移动一个位置，直到再次与原来的相遇点fast相遇。此时，slow所在的位置就是重复的整数。
        int slow = 0, fast = 0;
        // 第一次相遇
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // 再次初始化指针到数组起始位置
        slow = 0;
        // 第二次相遇
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.findDuplicate({1, 3, 4, 2, 2}) << endl;
    cout << s.findDuplicate({3, 1, 3, 4, 2}) << endl;
    cout << s.findDuplicate({3, 3, 3, 3, 3}) << endl;
    cout << s.findDuplicate({1, 4, 3, 1}) << endl;
    return 0;
}