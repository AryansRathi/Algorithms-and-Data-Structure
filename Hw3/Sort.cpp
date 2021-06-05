/*
CH-231-A
a3 p2.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/

#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;
using namespace std::chrono;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionsort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
    }
}
int *num(int size)
{
    srand(time(NULL));
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }
    return arr;
}
int main()
{
    ofstream myfile;
    myfile.open("Input.txt");
    int *arr;
    for (int size = 0; size < 1000; size += 10)
    {
        arr = num(size);
        arr[0] = size;

        auto start1 = high_resolution_clock::now();
        selectionsort(arr, size);
        auto stop1 = high_resolution_clock::now();
        ;
        auto worst = duration_cast<microseconds>(stop1 - start1);

        auto start2 = high_resolution_clock::now();
        selectionsort(arr, size);
        auto stop2 = high_resolution_clock::now();
        auto best = duration_cast<microseconds>(stop2 - start2);

        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            arr = num(size);

            auto start3 = high_resolution_clock::now();
            selectionsort(arr, size);
            auto stop3 = high_resolution_clock::now();

            auto total = (duration_cast<microseconds>(stop3 - start3));
            sum = sum + total.count();
        }

        double average = 0.0;
        average = sum / 5;

        myfile << size << " " << (double)worst.count() << " " << (double)best.count() << " " << average << endl;
    }
    myfile.close();
    return 0;
}