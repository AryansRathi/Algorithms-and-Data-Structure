#include "stack.h"
#include <iostream>
using namespace std;
int main()
{
    Stack<int> a(7);
    a.push(1);
    a.push(6);
    a.push(3);
    a.push(5);
    a.push(9);
    a.push(0);
    a.push(7);
    a.print();
    cout<<endl;
    cout << "Poping out the elements" << endl;
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    return 0;
}