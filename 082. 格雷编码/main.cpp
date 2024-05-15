#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * @brief 格雷编码生成器
 * 此类提供了一个公共方法 `grayCode`，用于生成指定位数的格雷编码序列。
 */
class Solution {
public:

    /**
     * @fn grayCode
     * @param n 位数，表示要生成的格雷编码的二进制位数
     * @return 返回一个整数向量，包含所有 n 位格雷编码
     *
     * 此方法使用迭代方式生成格雷编码序列：
     *
     * 1. 初始化向量 `v`，将初始的 0 位格雷编码添加到其中。
     * 2. 初始化变量 `head` 为 1，它代表当前位的翻转值。
     * 3. 遍历从 0 到 n-1，对于每个位数：
     *    a. 从后向前遍历当前已有的格雷编码 `v`，对每个编码 `v[j]`，将其与 `head` 相加并插入到 `v` 的末尾。
     *       这样做可以保证新生成的编码与前一个编码只有一个位不同。
     *    b. 将 `head` 左移一位，准备为下一次迭代生成新的翻转值。
     * 4. 返回完整的格雷编码向量 `v`。
     */
    vector<int> grayCode(int n) {
        vector<int> v; // 初始化空向量用于存储格雷编码
        v.push_back(0); // 添加初始的0位格雷编码

        int head = 1; // 初始化头位，用于生成下一个不同的位
        for (int i = 0; i < n; i++) { // 遍历n位
            for (int j = v.size() - 1; j >= 0; j--) { // 从后向前遍历已有的格雷编码
                v.push_back(head + v[j]); // 生成新的格雷编码并添加到向量中
            }
            head <<= 1; // 更新头位，左移一位
        }
        return v; // 返回格雷编码向量
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
    print(s.grayCode(1));
    print(s.grayCode(2));
    print(s.grayCode(3));
    return 0;
}