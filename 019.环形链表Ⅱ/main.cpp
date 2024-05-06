#include <iostream>
#include "../include/node.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        while (head != nullptr) {
            if (set.count(head)) {
                return head;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    ListNode *circle = new ListNode(2, new ListNode(0, new ListNode(-4)));
    circle->next = circle;
    ListNode *node = new ListNode(3, circle);
    cout << s.detectCycle(node) << endl;
    return 0;
}