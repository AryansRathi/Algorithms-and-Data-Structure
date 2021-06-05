#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int a = 0; // stroing the maximum element of the input array

void sort(int A[], int B[], int n)
{
    int count[a + 1], t;
    for (int i = 0; i <= a; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        t = A[i];
        count[t]++;
    }
    for (int i = 1; i <= a; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        t = A[i];
        B[count[t]] = t;
        count[t] = count[t] - 1;
    }
}

int main()
{
    int A[7] = {9, 1, 6, 7, 6, 2, 1};
    int B[7];
    for (int i = 0; i < 7; i++)
    {
        if(A[i]>a)
        {
            a=A[i];
        }

    }
    
    sort(A,B,7);
    
    for (int i = 1; i <= 7; i++)
    {
        cout<<B[i]<<" ";
    }
    return 0;
}
