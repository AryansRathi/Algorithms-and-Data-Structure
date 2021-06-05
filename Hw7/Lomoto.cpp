#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
//#define CLOCKS_PER_MILL (CLOCKS_PER_SEC/1000)
using namespace std;
int partition(int arr[], int p, int q)
{
    int pivot = arr[p];
    int i = p;

    for (int j = p + 1; j <= q; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[p], arr[i]);
    return i;
}

void quickSort(int arr[], int p, int q)
{
    if (p < q)
    {
        int a = partition(arr, p, q);
        quickSort(arr, p, a - 1);
        quickSort(arr, a + 1, q);
    }
}
int main()
{
    double Time = 0.0;
    double average = 0.0;
    ofstream myfile;
    myfile.open("Data1.txt");
    int arr[1000];
    clock_t start, stop;
    srand(time(NULL));
    for (int a = 0; a < 1000; a++)
    {
        arr[a] = (rand() % 1000);
    }
    for (int size = 0; size <= 100000; size++)
    {

        start = clock();
        quickSort(arr, 0, 1000);
        stop = clock();
        Time = ((double)(stop - start) / CLOCKS_PER_SEC);
        average = (average + Time)/100000;

        myfile << size << " " << Time << endl;
    }
    cout << "The average time is " << average <<endl;
    return 0;
}
//Refrence
//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/