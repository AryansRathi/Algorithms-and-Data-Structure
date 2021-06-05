#include "stack.h"
template <class T>
class Queue
{
private:
    Stack<T> a;
    Stack<T> b;
    int size;

public:
    Queue()
    {
        this->size = 0;
    }
    void Enqueue(T elem)
    {
        a.push(elem);
        size++;
    }
    T Dequeue()
    {
        if (b.isEmpty() == true)
        {
            while (!a.isEmpty())
            {
                T temp = a.pop();
                b.push(temp);
            }
        }
        this->size--;
        return b.pop();
    }
    bool isEmpty()
    {
        if (this->size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
