#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        bool negative = false;
        long long result = 0; // 使用long long类型来避免早期溢出

        // 跳过前导空白字符
        while (index < s.size() && s[index] == ' ') ++index;

        // 处理正负号
        if (index < s.size() && (s[index] == '+' || s[index] == '-')) {
            negative = (s[index++] == '-');
        }

        // 逐字符转换并累加，同时检查溢出
        while (index < s.size() && isdigit(s[index])) {
            int digit = s[index] - '0';
            // 检查乘以10后的结果是否会溢出
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return negative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + digit;
            ++index;
        }

        return negative ? -static_cast<int>(result) : static_cast<int>(result);
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("42.3") << endl;
    cout << s.myAtoi("+42") << endl;
    cout << s.myAtoi(" 42 ") << endl;
    cout << s.myAtoi("   -042") << endl;
    cout << s.myAtoi("1337c0d3") << endl;
    cout << s.myAtoi("0-1") << endl;
    cout << s.myAtoi("--2") << endl;
    cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("-91283472332") << endl;
    return 0;
}