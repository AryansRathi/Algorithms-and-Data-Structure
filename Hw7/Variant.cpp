#include <iostream>
using namespace std;
//split in three parts
int partition(int arr[], int p, int q, int *ptr)
{
    if (arr[p] > arr[p + 1])
    {
        swap(arr[p], arr[p + 1]);
    }
    int a = arr[p]; 
    int b = arr[p + 1];

    int r, i = p, j = p + 1;

    int index = j;
    
    for (r = p + 2; r <= q; r++)
    {
        if (arr[r] <= b)
        {
            j++;
            
            swap(arr[j], arr[r]);
            
            if (arr[j] <= a)
            {
                i++;
                swap(arr[i], arr[j]);
                if (arr[j] == b)
                {
                    index = j;
                }
                if (arr[i] == b)
                {
                    index = i;
                }
            }
        }
    }

    swap(arr[j], arr[index]);
    swap(arr[p], arr[i]);
    *ptr = j;
    return i;
}
//Randomized pivot points
int partition(int arr[],int p,int q)
{
    srand(time(NULL));
    int a=0,b=0;
    while(a==b)
    {
        a=rand()%q;
        b=rand()%q;
    }
swap(arr[a],arr[p]);
swap(arr[b],arr[p+1]);
quicksort(arr,p,q);
}

void quicksort(int arr[], int p, int q)
{
    if (q == 1)
    {
        if (arr[p] > arr[q])
        {
            swap(arr[p], arr[q]);
        }
        return;
    }
    if (p < q)
    {
        int j;
        int a = partition(arr, p, q, &j);
        quicksort(arr, 0, a - 1);
        quicksort(arr, a + 1, j - 1);
        quicksort(arr, j + 1, q);
    }
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int arr[] = {8,4,2,1,6,5};
    quicksort(arr, 0, 5);
    print(arr, 6);
    return 0;
}