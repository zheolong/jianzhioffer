#include <stdio.h>
#include <stack>
#include <stdlib.h>

template <typename T> class CQueue
{
    public:
        CQueue(void){};
        ~CQueue(void){};

        void appendTail(const T& node);
        T deleteHead();

    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
};

template <typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead()
{
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T t = stack1.top();
            stack2.push(t);
            stack1.pop();
        }
    }

    if (stack2.empty()) {
        printf("queue is empty");
    }

    T t = stack2.top();
    stack2.pop();

    return t;
}

int main(void)
{
    CQueue<int> cq;
    cq.appendTail(1);
    cq.appendTail(2);
    int head = cq.deleteHead(); printf("%d", head);
    cq.appendTail(3);
    head = cq.deleteHead(); printf("%d", head);
    cq.appendTail(4);
    head = cq.deleteHead(); printf("%d", head);
    head = cq.deleteHead(); printf("%d", head);
}
