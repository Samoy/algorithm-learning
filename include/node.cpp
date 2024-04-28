#include "node.h"
std::vector<int> ListNode::toArray() const
{
    std::vector<int> array;
    ListNode *current = const_cast<ListNode *>(this);

    while (current != nullptr)
    {
        array.push_back(current->val);
        current = current->next;
    }

    return array;
}

void ListNode::print() const
{
    std::vector<int> vec = this->toArray();
    std::cout << "[";
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << "]" << std::endl;
}