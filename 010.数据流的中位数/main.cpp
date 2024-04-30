#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<>> queMin;
    priority_queue<int, vector<int>, greater<>> queMax;


public:
    MedianFinder()
    = default;

    void addNum(int num) {
        if (queMin.empty() || num < queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

int main(int argc, char const *argv[]) {
    MedianFinder medianFinder{};
    medianFinder.addNum(1);                    // arr = [1]
    medianFinder.addNum(2);                    // arr = [1, 2]
    cout << medianFinder.findMedian() << endl; // 返回 1.5 ((1 + 2) / 2)
    medianFinder.addNum(3);                    // arr[1, 2, 3]
    cout << medianFinder.findMedian() << endl; // return 2.0
    return 0;
}
