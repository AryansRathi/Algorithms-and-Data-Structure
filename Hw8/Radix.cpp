#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void Bucketsort(vector<int> &arr, int power)
{
    if (power == 0)
    {
        return;
    }
    else
    {
        vector<int> Bucket[10];
        for (int i = 0; i < arr.size(); i++)
        {
            int pos = (arr[i] / power) % 10;
            Bucket[pos].push_back(arr[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            if (Bucket[i].size() > 1)
            {
                Bucketsort(Bucket[i], power / 10);
            }
        }
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < Bucket[i].size(); j++)
            {
                arr[index++] = Bucket[i][j];
            }
        }
    }
}

void Radixsort(vector<int> &arr)
{
    int maxnum = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[0] < arr[i])
        {
            maxnum = arr[i];
        }
    }
    int power = 1;
    while (maxmum / power > 10)
    {
        power = power * 10;
    }

    Bucketsort(arr, power)
}
int main()
{
    int n;
    cout << "Enter the Numbers" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the value" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}