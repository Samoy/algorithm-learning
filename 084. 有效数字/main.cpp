#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int state = 0; // 状态机的状态
        int len = s.length();
        bool has_decimal = false, has_exp = false, has_sign = false;

        for (int i = 0; i < len; i++) {
            char ch = s[i];

            if (std::isdigit(ch)) {
                if (state == 0) {
                    state = 1; // 遇到数字，进入整数或小数部分
                } else if (state == 3 || state == 4 || state == 6) {
                    state = 6; // 在小数点后或指数部分遇到数字
                }
            } else if (ch == '+' || ch == '-') {
                if (!has_sign && state != 2 && state != 5) {
                    has_sign = true;
                    if (state == 0) {
                        state = 1; // 符号前没有数字，但可以出现在指数部分
                    } else if (state == 3) {
                        state = 4; // 符号在小数点后
                    } else if (state == 5) {
                        state = 6; // 符号在指数前
                    }
                } else {
                    return false; // 符号出现次数过多或位置不正确
                }
            } else if (ch == '.') {
                if (state == 1 || state == 3) {
                    has_decimal = true;
                    state = 3; // 遇到小数点
                } else {
                    return false; // 小数点位置不正确
                }
            } else if (ch == 'e' || ch == 'E') {
                if (!has_exp && state == 1 || state == 3 || state == 4) {
                    has_exp = true;
                    state = 5; // 遇到指数标识符
                    has_sign = false; // 重置符号标志，因为指数可以有符号
                } else {
                    return false; // 指数标识符位置不正确
                }
            } else {
                return false; // 非数字、非符号、非小数点、非指数标识符
            }
        }

        return state == 1 || state == 3 || state == 4 || state == 6; // 结束状态判断
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.isNumber("0") << endl;
    cout << s.isNumber("e") << endl;
    cout << s.isNumber(".") << endl;
    cout << s.isNumber("Infinity") << endl;
    return 0;
}