#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *current = head;
        int i = 0;
        while (current != nullptr) {
            current = current->next;
            i++;
        }
        ListNode *middle = head;
        for (int j = 1; j <= i / 2; ++j) {
            middle = middle->next;
        }
        return middle;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    ListNode *node1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *node2 = new ListNode(1,
                                   new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    cout << s.middleNode(node1) << endl;
    cout << s.middleNode(node2) << endl;
    return 0;
}