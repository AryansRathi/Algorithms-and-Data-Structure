/*
CH-230-A
a4 p1.[c or cpp or h]
Firstname Lastname
myemail@jacobs-university.de
*/
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std::chrono;
using namespace std;

void insertionsort(int arr[], int l, int r)
{
    int i, j, temp;
    for (i = l + 1; i <= r; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= l && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void mergesort(int arr[], int l, int r, int a)
{

    if ((r - l) <= a)
    {
        insertionsort(arr, l, r);
    }
    else
    {
        int t = (l + r) / 2;
        mergesort(arr, l, t, a);
        mergesort(arr, t + 1, r, a);
        merge(arr, l, t, r);
    }
}

void merge(int arr[], int lb, int mid, int ub)
{
    int a = ub - mid;
    int b = mid - lb + 1;

    int Z[a];
    int T[b];
    int i, j, k;

    for (i = 0; i < b; i++)
        T[i] = arr[lb + i];
    for (j = 0; j < a; j++)
        Z[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = lb;

    while (i < b && j < a)
    {
        if (T[i] <= Z[j])
        {
            arr[k] = T[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = Z[j];
            k++;
            j++;
        }
    }

    while (i < b)
    {
        arr[k] = T[i];
        k++;
        i++;
    }
    while (j < a)
    {
        arr[k] = Z[j];
        k++;
        j++;
    }
}

int main()
{
    int size = 1000;
    int arr[size];
    ofstream myfile;
    myfile.open("Input.txt");

    for (int i = 0; i < size; i = i + 10)
    {
        //Average case
        srand(time(NULL));
        for (int a = 0; a < size; a++)
        {
            arr[a] = rand() % size;
        }
        auto start1 = high_resolution_clock::now();
        mergesort(arr, 0, size - 1, i);
        auto stop1 = high_resolution_clock::now();
        auto average = duration_cast<microseconds>(stop1 - start1);

        //worst case

        for (int a = 0; a < size; a++)
        {
            arr[a] = size - i;
        }

        auto start2 = high_resolution_clock::now();
        mergesort(arr, 0, size - 1, i);
        auto stop2 = high_resolution_clock::now();
        auto worst = duration_cast<microseconds>(stop2 - start2);

        // best case

        for (int a = 0; a < size; a++)
        {
            arr[a] = a;
        }

        auto start3 = high_resolution_clock::now();
        mergesort(arr, 0, size - 1, i);
        auto stop3 = high_resolution_clock::now();
        auto best = duration_cast<microseconds>(stop3 - start3);

        myfile << i << " " << (double)worst.count() << " " << (double)average.count() << " " << (double)best.count() << endl;
        cout << i << " " << (double)worst.count() << " " << (double)average.count() << " " << (double)best.count() << endl;
    }
    return 0;
}
//References
//https://www.geeksforgeeks.org/merge-sort/
//https://www.programiz.com/dsa/merge-sort