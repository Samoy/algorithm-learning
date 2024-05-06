#include <iostream>
#include "../include/node.h"

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

int main(int argc, char const *argv[]) {
    Solution s{};
    ListNode *nodeA = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));
    ListNode *nodeB = new ListNode(5,
                                   new ListNode(6, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5))))));
    cout << s.getIntersectionNode(nodeA, nodeB) << endl;
    return 0;
}