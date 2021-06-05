/*
CH-231-A
a2 p4.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 1; i < 31; i++)
    {
        v.push_back(i);
    }

    v.push_back(5);

    reverse(v.begin(), v.end());

    vector<int>::iterator itr;

    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }

    cout << endl;

    replace(v.begin(), v.end(), 5, 129);

    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << " ";
    }

    cout << endl;

    return 0;
}
//References
//http://www.cplusplus.com/reference/algorithm/replace/
//http://www.cplusplus.com/reference/algorithm/reverse/