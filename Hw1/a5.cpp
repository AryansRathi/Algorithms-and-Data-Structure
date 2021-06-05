/*
CH-231-A
a1 p5.[c or cpp or h]
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

    myvector.pop_back();

    cout << "Sring one" << endl;

    for (unsigned int i = 0; i < myvector.size(); i++)
    {
        cout << myvector[i] << " ";
    }

    cout << endl;

    cout << "String two" << endl;

    if (myvector.size() >= 6)
    {
        string tem = myvector[1];
        myvector[1] = myvector[4];
        myvector[4] = tem;
    }
    else
    {
        cout << "Swapping not possibel" << endl;
    }

    for (unsigned int i = 0; i < myvector.size(); i++)
    {
        cout << myvector[i] << " ";
    }
    cout << endl;

    myvector.back() = "???";

    cout << "Replacing the last element" << endl;

    for (unsigned int i = 0; i < myvector.size(); i++)
    {
        cout << myvector[i] << " ";
    }
    cout << endl;

    cout << "Separating by comma" << endl;

    vector<string>::iterator i;
    for (i = myvector.begin(); i != myvector.end(); ++i)
    {
        cout << *i;
        if (i != myvector.end() - 1)
            cout << ',';
    }

    cout << endl;

    cout << "Separating by semicolon" << endl;

    vector<string>::iterator a;
    for (a = myvector.begin(); a != myvector.end(); ++a)
    {
        cout << *a;
        if (i != myvector.end() - 1)
            cout << ';';
    }

    cout << endl;

    cout << "Reversing the string" << endl;

    vector<string>::iterator b;
    for (b = myvector.end() - 1; b != myvector.begin(); --b)
    {
        cout << *b;
        if (i != myvector.begin())
            cout << ';';
    }
    return 0;
}