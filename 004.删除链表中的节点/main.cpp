#include <iostream>
#include "../include/node.h"

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // 思路：删除某个节点，即将该节点变为下一个节点
        // 当前节点的val是一个节点的val
        node->val = node->next->val;
        // 当前节点的next是下一个节点的next
        node->next = node->next->next;
        // 更简单的
        // *node = *node->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(4);
    ListNode *five = new ListNode(5);
    ListNode *one = new ListNode(1);
    ListNode *nine = new ListNode(9);
    head->next = five;
    five->next = one;
    one->next = nine;
    Solution s{};
    s.deleteNode(five);
    head->print();
    return 0;
}
