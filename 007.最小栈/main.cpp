#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;
typedef unordered_map<string, int> Node;
class MinStack
{
private:
    int i = -1;
    Node current{};
    unordered_map<int, Node> map;

public:
    MinStack()
    {
    }

    void push(int val)
    {

        i++;
        if (i == 0)
        {
            current["min"] = val;
        }
        else
        {
            current["min"] = min(map[i - 1]["min"], val);
        }
        current["value"] = val;
        map[i] = current;
    }

    void pop()
    {
        if (i > -1)
        {
            i--;
        }
    }

    int top()
    {
        return map[i]["value"];
    }

    int getMin()
    {
        return map[i]["min"];
    }
};

int main(int argc, char const *argv[])
{
    MinStack minStack{};
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);
    minStack.top();
    minStack.pop();
    minStack.getMin();
    minStack.pop();
    minStack.getMin();
    minStack.pop();
    minStack.getMin();
    minStack.pop();
    minStack.getMin();
    return 0;
}
