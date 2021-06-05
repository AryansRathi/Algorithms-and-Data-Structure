#include<iostream>
#include"Hash.h"
using namespace std;
int main()
{
    HashTable H;
    H.insertNode(1, 1);
    H.insertNode(2, 3);
    H.insertNode(3, 4);
    H.insertNode(4, 5);
    H.insertNode(5, 6);
    H.insertNode(6, 7);
    H.insertNode(7, 8);
    H.print();
    cout << "Value of node with key 3 " << H.get(3) << endl;
    return 0;
}
//References
//https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
//https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/