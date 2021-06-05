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
void heapsort(int arr[], int size)
{
    buildheap(arr, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        size = size - 1;
        maxheapify(arr, size, 0);
    }
}
int main()
{
    ofstream myfile;
    myfile.open("Data.txt");
    for (int size = 0; size < 10000; size = size + 10)
    {
        int arr[size];
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % size;
        }
        auto start = high_resolution_clock::now();
        heapsort(arr, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        myfile << size << " " << (double)duration.count() << endl;
    }
    return 0;
}
//Reference
//https://www.geeksforgeeks.org/heap-sort/