/*
CH-231-A
a2 p2.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/

#include <deque>
#include <iostream>
using namespace std;
int main()
{
    deque<float> A;
    float f;
    while (cin >> f)
    {
        if (f == 0)
        {
            break;
        }
        else if (f > 0)
        {
            A.push_back(f);
        }

        else
        {
            A.push_front(f);
        }
    }

    cout << "Printing the deque" << endl;

    deque<float>::iterator r;

    for (r = A.begin(); r != A.end(); r++)
    {
        cout << *r << " ";
    }

    cout << endl;

    for (r = A.begin(); r != A.end(); r++)
    {
        if (*r > 0)
        {
            A.insert(r, 0);
            break;
        }
    }

    cout << "Printing the with comma" << endl;

    for (r = A.begin(); r != A.end(); r++)
    {
        cout << *r << ",";
    }

    cout << endl;
    return 0;
}
//References
//https://www.cplusplus.com/reference/deque/deque/insert/