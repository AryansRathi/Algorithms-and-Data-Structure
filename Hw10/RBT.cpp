#include"RBT.h"
#include<iostream>
using namespace std;
int main()
{
    RedBlackTree Tree;
    Tree.insert(10);
    Tree.insert(22);
    Tree.insert(45);
    Tree.insert(2);
    Tree.insert(77);
    Tree.insert(81);
    cout << "Red Balck Tree Is"<< endl;
    Tree.print();
    Tree.search(2);
    Tree.search(15);
    cout << "Minimum element "<< Tree.getMinimum()->data << endl;
    cout << "Maximum element "<< Tree.getMaximum()->data << endl;
    Tree.deleteN(77);
}