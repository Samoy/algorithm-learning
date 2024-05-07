#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        // 确保num1是较长的数，如果num2更长则交换两者
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }

        // 在较短的数字前补零，使两个数字长度相同
        int diff = num1.length() - num2.length();
        num2 = string(diff, '0') + num2;

        int carry = 0; // 进位标志
        string result = ""; // 存储结果

        // 从低位到高位逐位相加
        for (int i = num1.length() - 1; i >= 0; --i) {
            int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            result = to_string(sum % 10) + result; // 当前位的和
            carry = sum / 10; // 更新进位
        }

        // 如果最后还有进位，则在结果最前面加上
        if (carry > 0) {
            result = to_string(carry) + result;
        }

        return result;
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
//    cout << s.addStrings("11", "123") << endl;
//    cout << s.addStrings("456", "77") << endl;
//    cout << s.addStrings("0", "0") << endl;
//    cout << s.addStrings("6913259244", "71103343") << endl;
    cout << s.addStrings("9333852702227987", "85731737104263") << endl;
    return 0;
}