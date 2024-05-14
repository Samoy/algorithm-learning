#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 初始化ret为0，相当于将数组中的第一个元素与0异或，结果就是第一个元素。
     * 接下来，对于数组中的每个元素e，我们执行ret ^= e。如果e在数组中出现了两次，那么ret会先与e异或，然后再次与e异或，由于异或的交换律，两次异或抵消，ret的值不会改变。
     * 然而，如果某个元素e只出现一次，那么它不会被再次异或，ret的值会变为该元素的值。
     * 最后，当遍历完整个数组后，ret中保留的就是数组中出现一次的数字
     */
    int singleNumber(const vector<int> &nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.singleNumber({2, 2, 1}) << endl;
    cout << s.singleNumber({4, 1, 2, 1, 2}) << endl;
    cout << s.singleNumber({1}) << endl;
    cout << s.singleNumber({1, 0, 1}) << endl;
    return 0;
}