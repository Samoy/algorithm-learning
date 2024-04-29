#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> forward;
    stack<int> rear;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        forward.push(x);
        // 构造rear
        rear = stack<int>{};
        stack<int> current = forward;
        while (!current.empty())
        {
            rear.push(current.top());
            current.pop();
        }
    }

    int pop()
    {
        int top = rear.top();
        rear.pop();
        // 构造forward
        forward = stack<int>{};
        stack<int> current = rear;
        while (!current.empty())
        {
            forward.push(current.top());
            current.pop();
        }
        return top;
    }

    int peek()
    {
        return rear.top();
    }

    bool empty()
    {
        return rear.empty();
    }
};

int main(int argc, char const *argv[])
{
    MyQueue myQueue{};
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.pop();
    myQueue.push(5);
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    return 0;
}
