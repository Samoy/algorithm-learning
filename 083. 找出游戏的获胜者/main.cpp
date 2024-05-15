#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // 使用O(n)空间复杂度
    int findTheWinner(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        // 设置当前指针
        int current = 0;
        while (v.size() > 1) {
            current += k - 1;
            if (current >= v.size()) {
                current = current % v.size();
            }
            v.erase(v.begin() + current);
        }
        return v[0];
    }

    // 使用O(1)空间复杂度
    int findTheWinner2(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++) {
            winner = (winner + k - 1) % i;
        }
        return winner;
    }
};


int main(int argc, char const *argv[]) {
    Solution s{};
    cout << s.findTheWinner(5, 2) << endl;
    cout << s.findTheWinner(6, 5) << endl;
    cout << s.findTheWinner2(5, 2) << endl;
    cout << s.findTheWinner2(6, 5) << endl;
    return 0;
}