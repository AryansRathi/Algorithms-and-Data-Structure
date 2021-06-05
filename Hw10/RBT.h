#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
enum Color
{
    RED,
    BLACK
};
struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};
class RedBlackTree
{
private:
    Node *root;

protected:
    void rotateLeft(Node *&data)
    {
        Node *a = data->right;
        data->right = a->left;
        if (a->right != NULL)
        {
            a->right->parent = data;
        }
        a->parent = data->parent;
        if (data->parent == NULL)
        {
            root = a;
        }
        else if (data == data->parent->left)
        {
            data->parent->left = a;
        }
        else
        {
            data->parent->right = a;
        }
        a->left = data;
        data->parent = a;
    }
    void rotateRight(Node *&data)
    {
        Node *a = data->left;
        data->left = a->right;
        if (a->left != NULL)
        {
            a->left->parent = data;
        }
        a->parent = data->parent;
        if (data->parent == NULL)
        {
            root = a;
        }
        else if (data == data->parent->left)
        {
            data->parent->left = a;
        }
        else
        {
            data->parent->right = a;
        }
        a->right = data;
        data->parent = a;
    }

public:
    RedBlackTree()
    {
        root = NULL;
    }
    void insert(int n)
    {
        Node *a = NULL;
        Node *b = root;
        Node *c = new Node;
        c->data = n;
        c->left = NULL;
        c->right = NULL;
        c->color = RED;
        while (b != NULL)
        {
            a = b;
            if (c->data < b->data)
            {
                b = b->left;
            }
            else
            {
                b = b->right;
            }
        }
        c->parent = a;
        if (a == NULL)
        {
            root = c;
        }
        else if (c->data < a->data)
        {
            a->left = c;
        }
        else
        {
            a->right = c;
            c->left = NULL;
            c->right = NULL;
            c->color = RED;
            RB_fixup(root, c);
        }
    }
    void RB_fixup(Node *&root, Node *&temp)
    {
        if (temp == root)
        {
            root->color = BLACK;
            return;
        }
        Node *uncle;
        while (temp->parent != NULL && temp->parent->color == RED)
        {
            if (temp->parent == temp->parent->parent->left)
            {
                uncle = temp->parent->parent->right;
                if (uncle == NULL)
                {
                    if (temp == temp->parent->right)
                    {
                        temp = temp->parent;
                        rotateLeft(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;
                    rotateRight(temp->parent->parent);
                }
                else if (uncle->color == BLACK)
                {
                    if (temp == temp->parent->right)
                    {
                        temp = temp->parent;
                        rotateLeft(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;
                }
                else
                {
                    temp->parent->color = BLACK;
                    uncle->color = BLACK;
                    temp->parent->parent->color = RED;
                    temp = temp->parent->parent;
                }
            }

            else
            {
                uncle = temp->parent->parent->left;
                if (uncle == NULL)
                {
                    if (temp == temp->parent->left)
                    {
                        temp = temp->parent;
                        rotateRight(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;

                    rotateLeft(temp->parent->parent);
                }

                else if (uncle->color == BLACK)
                {
                    if (temp == temp->parent->left)
                    {
                        temp = temp->parent;
                        rotateRight(temp);
                    }
                    temp->parent->color = BLACK;
                    temp->parent->parent->color = RED;
                    rotateLeft(temp->parent->parent);
                }

                else
                {
                    temp->parent->color = BLACK;
                    uncle->color = BLACK;
                    temp->parent->parent->color = RED;
                    temp = temp->parent->parent;
                }
            }
            root->color = BLACK;
        }
    }
    void Transplant(Node *a, Node *b)
    {
        if (a->parent == NULL)
        {
            root = b;
        }
        else if (a == a->parent->left)
        {
            a->parent->left = b;
        }
        else
        {
            a->parent->right = b;
        }
        if (b != NULL)
        {
            b->parent = a->parent;
        }
    }
    void deletenode(Node *z)
    {
        Node *y;
        Node *x;
        int yoriginalcolor;
        y = z;
        yoriginalcolor = y->color;

        if (z->left == NULL)
        {
            x = z->right;
            Transplant(z, z->right);
        }
        else if (z->right == NULL)
        {
            x = z->left;
            Transplant(z, z->left);
        }
        else
        {
            y = findMinimum(z->right);
            yoriginalcolor = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (yoriginalcolor == BLACK)
        {
            RBfix(x);
        }
    }
    void RBfix(Node *&x)
    {
        Node *w;
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                w = x->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x->parent->color = BLACK;
                    x = x->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->color = RED;
                        w->left->color = BLACK;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    x->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            }
            else
            {
                w = x->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = BLACK;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x->parent->color = BLACK;
                    x = x->parent;
                }
                else
                {
                    if (w->left->color == BLACK)
                    {
                        w->color = RED;
                        w->right->color = BLACK;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }

        x->color = BLACK;
    }
    void deleteN(int val)
    {
        Node *z = NULL;
        z = searchBST(root,val);
        deletenode(z);
        cout << "Element deleted" << endl;
    }
    Node *predecessor(Node *&a)
    {
        if (a->left != NULL)

            return findMaximum(a->left);
        Node *p = a->parent;
        while (p != NULL && a == p->left)
        {
            a = p;
            p = p->parent;
        }

        return p;
    }
    Node *successor(Node *&a)
    {
        if (a->right != NULL)

            return findMinimum(a->right);

        Node *p = a->parent;
        while (p != NULL && a == p->right)
        {
            a = p;
            p = p->parent;
        }
        return p;
    }
    Node *getMinimum()
    {
        Node *a = root;
        while (a->left != NULL)
        {
            a = a->left;
        }
        return a;
    }
    Node *getMaximum()
    {

        Node *a = root;
        while (a->right != NULL)
        {
            a = a->right;
        }
        return a;
    }

   Node *findMinimum(Node *&root)
   {
       while (root->left!=NULL)
       {
           root=root->left;
       }
       return root;
   }
   Node *findMaximum(Node *&root)
   {
       while (root->right!=NULL)
       {
        root=root->right;
       }
       return root;
   }
    Node *searchBST(Node *a, int val)
    {
        if (a == NULL || a->data == val)
        {
            return a;
        }
        if (val > a->data)
        {
            return searchBST(a->right,val);
        }
        else
        {
            return searchBST(a->left,val);
        }
    }

    void search(int val)
    {
        cout << "Search element with value" << val << endl;
        searchBST(root, val);
        if (searchBST(root, val) == NULL)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            cout << "Element" << searchBST(root, val)->data << " found " << endl;
        }
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data<<endl;
        inorder(root->right);
    }
    void print()
    {
        inorder(root);
        cout << endl;
    }
};
