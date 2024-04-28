#include <iostream>
#include "../include/node.h"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *current = head;
        ListNode *result = nullptr;
        while (current != nullptr)
        {
            std::cout << current->val << std::endl;
            // 如果小于x，放在前面
            if (current->val < x)
            {
                result = current;
            }
            // 否则放在后面
            else
            {
                result->next = current->next;
            }
            current = current->next;
        }
        return result;
    }
};

int main()
{
    Solution s{};
    ListNode *source = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    ListNode *target = s.partition(source, 3);
    target->print();
    return 0;
}