#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void Bucketsort(float A[], int size)
{
    vector<float> b[size];
    
    for (int i = 0; i < size; i++)
    {
        int a = size * A[i];
        b[a].push_back(A[i]);
    }
    for (int i = 0; i < size; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    int index = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            A[index++] = b[i][j];
        }
    }
}
int main()
{
    float A[] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    int n = sizeof(A) / sizeof(A[0]);
    Bucketsort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " " << endl;
    }
    return 0;
}