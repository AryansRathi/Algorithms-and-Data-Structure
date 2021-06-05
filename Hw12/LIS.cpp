#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &arr)
{
    for (int a : arr)
    {
        cout << a << " "<<endl;
    }
}
void LIS(int a[], int Size)
{
    vector<vector<int>> arr(Size);

    arr[0].push_back(a[0]);

    for (int i = 1; i < Size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((a[i] > a[j]) && (arr[i].size() < arr[j].size()))

                arr[i] = arr[j];
        }
        arr[i].push_back(a[i]);
    }

    vector<int> max = arr[0];

    for (vector<int> i : arr)

        if (i.size() > max.size())

            max = i;

    print(max);
}

int main()
{
    int arr[] = {8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    LIS(arr, size);
    return 0;
}