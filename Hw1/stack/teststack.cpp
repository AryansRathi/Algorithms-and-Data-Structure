/*
CH-231-A
a1 p4.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/

#include "stack.h"
#include <iostream>
using namespace std;
int main()
{
    Stack<int> intstack(10);

    for (int i = 0; i <= 9; i++)
    {
        intstack.push(i);
    }
    cout << endl;

    cout <<"Psuhing 10 elements in stack"<< endl;

    cout << "The total number of enteries are currently" << endl;

    cout << intstack.getNumEntries();

    cout << endl;

    cout << "last element from the back function is:" << endl;

    cout << intstack.back();

    cout << endl;

    int out;

    cout << "popping out element one by one:" << endl;

    intstack.pop(out);

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << out << endl;

    intstack.pop(out);

    cout << endl;

    cout << "The total number of enteries"<< endl;

    cout << intstack.getNumEntries();

    return 0;
}