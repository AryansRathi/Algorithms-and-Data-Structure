/*
CH-231-A
a1 p4.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> myvector;
    string word;
    do
    {
        getline(cin, word);
        myvector.push_back(word);
    } while (word != "END");

    myvector.pop_back();//excluding the last element

    for (unsigned int i = 0; i < myvector.size(); i++)
    {
        cout << myvector[i] << " ";
    }

    vector<string>::iterator i;
    for (i = myvector.begin(); i != myvector.end(); ++i)
    {
        cout << *i;
        if (i != myvector.end() - 1)
            cout << ',';
    }

    return 0;
}
//Reference
//https://www.geeksforgeeks.org/introduction-iterators-c/#:~:text=An%20iterator%20is%20an%20object,that%20particular%20location%20using%20them.
//https://www.youtube.com/watch?v=Cq1h1KPoGBU&ab_channel=programminghelporg