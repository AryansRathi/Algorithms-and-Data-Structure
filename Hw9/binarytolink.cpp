#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class treeNode
{
public:
    int data;
    treeNode *left;
    treeNode *right;
    treeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *sortedList(Node *head, treeNode *root)
{
    if (root == NULL)
    {
        return head;
    }

    head = sortedList(head, root->left);
    Node *newNode = new Node(root->data);
    Node *temp = head;
    Node *prev = NULL;
    if (temp == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data > root->data)
            {
                break;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    if (temp == NULL)
    {
        prev->next = newNode;
    }
    else
    {
        if (prev == NULL)
        {
            newNode->next = temp;
            head = newNode;
        }
        else
        {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
    head = sortedList(head, root->right);
    return head;
}
