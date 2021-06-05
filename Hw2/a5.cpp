/*
CH-231-A
a2 p5.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/

#include <ctime>
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> Lottery;
    int num;
    srand(time(NULL));
    while (lottery.size() <= 6)
    {
        Lottery.insert(NUM());
    }

    set<int> iterator::itr;
    for (itr = Lottery.begin(); itr != Lottery.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}
int NUM()
{
    int num = rand() % 49 + 1;
    return num;
}
//Refrence
//https://www.cplusplus.com/reference/cstdlib/rand/