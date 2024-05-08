#include <iostream>

using namespace std;


class Solution {
private:
    bool isBadVersion(int version) {
        return version >= 4;
    }

public:
    int firstBadVersion(int n) {
        // 初始化左边界为1，右边界为n
        int left = 1, right = n;

        // 当左边界小于等于右边界时，继续二分查找
        while (left <= right) {
            // 计算中间版本号
            int mid = (right - left) / 2 + left;

            // 检查中间版本是否是错误的
            bool current = isBadVersion(mid);

            // 检查前一个版本是否是正确的
            bool previous = isBadVersion(mid - 1);

            // 如果前一个版本是正确的，当前版本是错误的，说明第一个错误版本就是mid
            if (!previous && current) return mid;

                // 如果当前版本和前一个版本都是错误的，说明错误版本在mid的左边，更新右边界
            else if (current) {
                right = mid - 1;
            }
                // 如果当前版本和前一个版本都是正确的，说明错误版本在mid的右边，更新左边界
            else {
                left = mid + 1;
            }
        }
        // 如果找不到错误版本，返回-1
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.firstBadVersion(3) << endl;
    cout << s.firstBadVersion(4) << endl;
    cout << s.firstBadVersion(5) << endl;
    cout << s.firstBadVersion(6) << endl;
    return 0;
}