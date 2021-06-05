#include <chrono>
#include <fstream>
#include <iostream>
using namespace std::chrono;
using namespace std;
int partition(int arr[], int p, int q)
{
    int pivot = arr[p];
    int i = p - 1, j = q + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int p, int q)
{
    if (p < q)
    {
        int a = partition(arr, p, q);
        quickSort(arr, p, a);
        quickSort(arr, a + 1, q);
    }
}
int main()
{
    double Time = 0.0;
    double average = 0.0;
    ofstream myfile;
    myfile.open("Data2.txt");
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
    cout << "The average time is " << average << endl;
    return 0;
}
//Refrence
//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/