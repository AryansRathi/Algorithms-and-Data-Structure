/*
CH-231-A
a6 p2.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;
using namespace ::chrono;
void maxheapify(int arr[], int size, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[large])
    {
        large = left;
    }

    if (right < size && arr[right] > arr[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(arr[i], arr[large]);

        maxheapify(arr, size, large);
    }
}
void buildheap(int arr[], int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        maxheapify(arr, size, i);
    }
}
// void heapsort(int arr[], int size)
// {
//     buildheap(arr, size);
//     for (int i = size - 1; i >= 1; i--)
//     {
//         swap(arr[0], arr[i]);
//         size = size - 1;
//         maxheapify(arr, size, 0);
//     }
// }
int down(int arr[], int size, int i)
{
    int index = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= size)
    {
        return i;
    }
    if (right >= size)
    {
        swap(arr[i],arr[left]);
        return left;
    }
    if (arr[left] > arr[right])
    {
        swap(arr[i],arr[left]);
        index = left;
    }
    else
    {
        swap(arr[i],arr[right]);
        index = right;
    }
    return down(arr, size, index);
}

void check(int arr[], int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] < arr[i])
    {
        swap(arr[i],arr[parent]);
        check(arr,parent);
    }
}
void heapsortvariant(int arr[], int size)
{
    buildheap(arr, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        int pos = down(arr, size-1, 0);
        check(arr,pos);
    }
}
int main()
{
    ofstream myfile;
    myfile.open("Variant.txt");
    for (int size = 0; size < 10000; size = size + 10)
    {
        int arr[size];
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % size;
        }
        auto start1 = high_resolution_clock::now();
        heapsortvariant(arr, size);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);

        // auto start2 = high_resolution_clock::now();
        // heapsortvariant(arr, size);
        // auto stop2 = high_resolution_clock::now();
        // auto duration2 = duration_cast<microseconds>(stop2 - start2);
        myfile << size << " " << (double)duration1.count() << endl;
    }
    return 0;
}