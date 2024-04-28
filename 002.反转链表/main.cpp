#include <iostream>
#include <vector>
#include <../include/node.h>

class Solution
{
public:
    // 使用迭代
    ListNode *reverseList1(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current != nullptr)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    // 使用递归
    ListNode *reverseList2(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *newHead = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main()
{
    Solution s{};
    ListNode *source1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *target1 = s.reverseList1(source1);
    std::cout << "Iterator: ";
    target1->print();
    ListNode *source2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *target2 = s.reverseList2(source2);
    std::cout << "Recursion: ";
    target2->print();
    return 0;
}