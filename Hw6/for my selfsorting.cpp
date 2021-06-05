#include <iostream>
#include<time.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}
int main()
{
    int size = 1000;
    int arr[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }
    bubblesort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
return 0;
}