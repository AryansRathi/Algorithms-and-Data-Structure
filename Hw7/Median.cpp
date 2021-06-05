#include <chrono>
#include <fstream>
#include <iostream>
using namespace std::chrono;
using namespace std;
int partition(int arr[], int p, int q)
{
    int pivot, right, left;
    left = p;
    right = q;
    pivot = arr[p];
    while (left < right)
    {
        while (arr[right] > pivot)

            right--;
        while ((left < right) && (arr[left] <= pivot))
            left++;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    arr[p] = arr[right];
    arr[right] = pivot;

    return right;
}
void quicksort(int arr[], int p, int q)
{
    int pos;
    if (p < q)
    {
        pos = partition(arr, p, q);
        quicksort(arr, p, pos - 1);
        quicksort(arr, pos + 1, q);
    }
}
int main()
{
   double Time;
    double average = 0.0;
    ofstream myfile;
    myfile.open("Data3.txt");
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
        quicksort(arr, 0, 1000);
        stop = clock();
        Time =((double)(stop - start) / CLOCKS_PER_SEC);
        average = (average + Time)/100000;

        myfile << size << " " << Time << endl;
    }
    cout << "The average time is " << average << endl;
    return 0;
}