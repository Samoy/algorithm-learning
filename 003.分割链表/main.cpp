#include <iostream>
#include "../include/node.h"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
            return nullptr;
        // 创建两个新的伪头节点，用于构建小于x和大于等于x的链表
        ListNode *before_head = new ListNode();
        ListNode *after_head = new ListNode();

        ListNode *before_curr = before_head;
        ListNode *after_curr = after_head;

        while (head)
        {
            if (head->val < x)
            {
                // 当前节点值小于x，添加到before链表
                before_curr->next = head;
                before_curr = before_curr->next;
            }
            else
            {
                // 当前节点值大于等于x，添加到after链表
                after_curr->next = head;
                after_curr = after_curr->next;
            }
            // 移动原链表的头到下一个节点
            head = head->next;
        }

        // 将两个链表连接起来
        after_curr->next = nullptr;           // 确保after链表末尾是NULL
        before_curr->next = after_head->next; // 将before链表的尾部连接到after链表的头部

        // 返回新链表的头节点，即before_head的下一个节点
        return before_head->next;
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