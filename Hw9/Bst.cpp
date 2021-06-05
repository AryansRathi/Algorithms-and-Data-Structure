#include<iostream>
using namespace std;
class Lnode
{
    public:
    int data;
    Lnode * next;
};
class BNode
{
public:
int data;
BNode* left;
BNode* right;
};

BNode* newNode(int data);
int countLNodes(LNode *head);
BNode* BST(Lnode **head,int n) 

BNode* SBST(Lnode *head)
{
    int n=countLNodes(head);
    return BST(&head,n) ;
}