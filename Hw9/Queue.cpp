#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    Queue<int> a;
    a.Enqueue(6);
    a.Enqueue(4);
    a.Enqueue(5);
    a.Enqueue(3);
    a.Enqueue(7);
    a.Enqueue(1);
    cout << a.Dequeue() << endl;
    cout << a.Dequeue() << endl;
    cout << a.Dequeue() << endl;
    cout << a.Dequeue() << endl;
    cout << a.Dequeue() << endl;
    cout << a.Dequeue() << endl;
    return 0;
}