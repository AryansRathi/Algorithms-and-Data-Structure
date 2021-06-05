#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int value;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
class HashTable
{
private:
    Node **arr;
    int maxSize;
    int currentSize;

public:
    HashTable()
    {
        maxSize = 100;
        currentSize = 0;
        arr = new Node *[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            arr[i] = NULL;
        }
    }
    int hashCode(int key)
    {
        return key % maxSize;
    }
    void insertNode(int key, int value)
    {
        int a = hashCode(key);
        while (arr[a] != NULL && arr[a]->key != key)
        {
            a = hashCode(a + 1);
        }
        if (arr[a] != NULL)
            delete arr[a];
        arr[a] = new Node(key, value);
    }
    int get(int key)
    {
        int hashIndex = hashCode(key);
        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key)
        {
            hashIndex = hashCode(hashIndex + 1);
        }
        if (arr[hashIndex] == NULL)
        {
            return -1;
        }
        else
        {
            return arr[hashIndex]->value;
        }
    }

    bool isEmpty()
    {
        if (this->currentSize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        for (int i = 0; i < maxSize; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1)
            {
                cout << "key = " << arr[i]->key
                     << "  value = " << arr[i]->value << endl;
            }
        }
    }
};
