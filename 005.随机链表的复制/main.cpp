#include <iostream>
#include "../include/node.h"
#include <unordered_map>

class Solution
{
public:
    std::unordered_map<Node *, Node *> cachedNode;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (!cachedNode.count(head))
        {
            Node *newNode = new Node(head->val);
            cachedNode[head] = newNode;
            newNode->next = copyRandomList((Node *)head->next);
            newNode->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};

int main(int argc, char const *argv[])
{
    Node *firstNode = new Node(7);
    Node *secondNode = new Node(13);
    Node *thirdNode = new Node(11);
    Node *fourthNode = new Node(10);
    Node *fiveNode = new Node(1);
    firstNode->next = secondNode;
    firstNode->random = nullptr;
    secondNode->next = thirdNode;
    secondNode->random = firstNode;
    thirdNode->next = fourthNode;
    thirdNode->random = fiveNode;
    fourthNode->next = fiveNode;
    fourthNode->random = thirdNode;
    fiveNode->next = nullptr;
    fiveNode->random = firstNode;
    Solution s{};
    Node *target = s.copyRandomList(firstNode);
    target->print();
    return 0;
}
