#include <algorithm>
#include <iostream>
using namespace std;
struct Activity
{
    int start, finish;
};
bool compare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}
void printMaxActivity(Activity arr[], int n)
{
    sort(arr, arr + n, compare);

    cout << "Selected activity" << endl;

    int i = 0;

    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << ", "
                 << arr[j].finish << "), ";
            i = j;
        }
    }
}
int main()
{
    Activity arr[] = {{1, 2}, {2, 9}, {7, 10}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivity(arr, n);
    return 0;
}
