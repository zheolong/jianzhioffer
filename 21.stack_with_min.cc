#include <stdio.h>
#include <stdlib.h>
#include <stack>

class StackWithMin 
{
    public:
        void push(int n);
        int top();
        void pop();
        int min();
    private:
        std::stack<int> data_stack;
        std::stack<int> min_stack;
};

void StackWithMin::push(int n)
{
    data_stack.push(n);
    if (min_stack.empty())
        min_stack.push(n);
    else
        min_stack.push(n < min_stack.top() ? n : min_stack.top());
}

int StackWithMin::top()
{
    if (!data_stack.empty())
        return data_stack.top();
    else
        exit(EXIT_FAILURE);
}

void StackWithMin::pop()
{
    data_stack.pop();
    min_stack.pop();
}

int StackWithMin::min()
{
    return min_stack.top();
}

int main(void)
{
    StackWithMin swm;
    swm.push(1);
    swm.push(2);
    swm.push(3);
    swm.push(0);
    printf("min:%d\n",swm.min());
    swm.pop();
    printf("min:%d\n",swm.min());
}
