#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = v.size() - 1; j >= 0; j--) {
                v.push_back(head + v[j]);
            }
            head <<= 1;
        }
        return v;
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