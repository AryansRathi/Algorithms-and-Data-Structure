/*
CH-231-A
a2 p1.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/
#include <fstream>
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> A;
    
    list<int> B;
    
    int a;
    
    cout<<"Enter the integers"<<endl;
    
    cin >> a;
    
    while (a > 0)
    {
        A.push_back(a);
        B.push_front(a);
        cin >> a;
    }
    
    list<int>::iterator itr;
    cout << "LIST A" << endl;
    for (itr = A.begin(); itr != A.end(); itr++)
    {
        cout << *itr << " ";
    }
    
    cout << endl;
    
    cout << "Printing list B in the file" << endl;
    
    ofstream myfile;
    
    myfile.open("listB.txt", ios::out);
    
    if (!myfile)
    {
        cout << "Error: file could not be opened" << endl;
        exit(0);
    }
    
    list<int>::iterator r;
    
    for (r = B.begin(); r != B.end(); r++)
    {
        myfile << *r << " ";
    }

    cout << endl;

    cout << "Moving elements in List A" << endl;

    A.splice(A.end(), A, A.begin());
    cout << endl;

    cout << "Moving elements in List B" << endl;
    B.splice(B.end(), B, B.begin());

    cout << "Printing list A with comma" << endl;
    for (itr = A.begin(); itr != A.end(); itr++)
    {
        cout << *itr << " , ";
    }

    cout << "Printing list B with comma" << endl;

    for (r = B.begin(); r != B.end(); r++)
    {
        cout << *r << " , ";
    }

    cout << endl;

    A.merge(B);
    
    A.sort();
   
    cout << "Sorted list" << endl;
    
    for (itr = A.begin(); itr != A.end(); itr++)
    {
        cout << *itr << " ";
    }
    
    cout << endl;
    
    return 0;
}
//References
//http://www.cplusplus.com/reference/list/list/splice/
//https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm