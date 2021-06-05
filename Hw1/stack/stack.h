/*
CH-231-A
a1 p5.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *arr;

    int size;

    int top;

public:
    Stack();

    Stack(const Stack &);

    Stack(int size);

    bool push(T element);

    bool pop(T &out);

    T back(void);

    int getNumEntries();

    ~Stack();

    void print();
};

template <class T>
Stack<T>::Stack(const Stack &a)
{
    size = a.size;
    arr = new T[a.size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = a.arr[i];
    }
    top = a.top;
}

template <class T>
Stack<T>::Stack(int newsize)
{
    size = newsize;
    arr = new T[size];
    top = -1;
}

template <class T>
Stack<T>::Stack()
{
    int size = 10;
    arr = new T[size];
    top = -1;
}

template <class T>
bool Stack<T>::pop(T &out)
{
    if (top == -1)
    {
        return false;
    }
    else
    {
        out = arr[top];
        top = top - 1;
        return true;
    }
}

template <class T>
T Stack<T>::back()
{
    return arr[top];
};

template <class T>
int Stack<T>::getNumEntries()
{
    return top + 1;
}

template <class T>
bool Stack<T>::push(T element)
{
    if (top + 1 == size)
    {
        return false;
    }
    else
    {
        top = top + 1;
        arr[top] = element;
        return true;
    }
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr;
}
//Reference
//https://www.techiedelight.com/stack-implementation-using-templates/