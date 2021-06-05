#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
    struct StackNode
    {
        T data;
        StackNode *next;
    };
    StackNode *top;
    int size;
    int current_size;

public:
    Stack(int new_size)
    {
        this->size = new_size;
        this->current_size = 0;
        this->top = NULL;
    }
    Stack()
    {
        this->size = -1;
        this->current_size = 0;
        this->top = NULL;
    }
    void push(T x)
    {
        if (this->current_size == this->size)
        {
            cout << "Stack overflow!" << endl;
        }
        else
        {
            struct StackNode *temp = new StackNode;
            temp->data = x;
            temp->next = top;
            top = temp;
            current_size++;
        }
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return 0;
        }
        else
        {
            T elem = top->data;
            top = top->next;
            current_size--;
            return elem;
        }
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        StackNode *ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};

//References
//https://codeforwin.org/2018/08/stack-implementation-using-linked-list-push-pop.html