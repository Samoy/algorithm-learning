#include <iostream>
#include <vector>
#include "../include/node.h"
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

int main()
{
    Solution *s{};
    // Test Case 1
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    std::cout << "Test Case 1: ";
    s->mergeTwoLists(l1, l2)->print();
    // Test Case 2
    l1 = nullptr;
    l2 = nullptr;
    std::cout << "Test Case 2: ";
    s->mergeTwoLists(l1, l2)->print();
    // Test Case 3
    l1 = nullptr;
    l2 = new ListNode(0);
    std::cout << "Test Case 3: ";
    s->mergeTwoLists(l1, l2)->print();
    return 0;
}