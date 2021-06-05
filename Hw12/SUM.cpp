#include <iostream>
using namespace std;
#define A 100
int maxPathsum(int tri[][A], int m, int n)
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (tri[i + 1][j] > tri[i + 1][j + 1])
            {
                tri[i][j] += tri[i + 1][j];
            }
            else
            {
                tri[i][j] += tri[i + 1][j + 1];
            }
        }
    }
    return tri[0][0];
}
void SUMhelp(int data[][A], int sums[][A], int i, int j, int n)
{
    if (i + 1 >= n or j + 1 >= n)
    {
        cout << data[i][j];
    }
    else
    {
        cout << data[i][j];
        if (sums[i + 1][j] > sums[i + 1][j + 1])
        {
            SUMhelp(data, sums, i + 1, j, n);
        } //if left child is max
        else
        {
            //if right child is max
            SUMhelp(data, sums, i + 1, j + 1, n);
        }
    }
}

void SUMPATH(int data[][A], int sums[][A], int n)
{

    SUMhelp(data, sums, 0, 0, n);
}

void showpath1(int tri[][A], int m, int n)
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((tri[i + 1][j] > tri[i + 1][j + 1]) && ((tri[i][j] += tri[i + 1][j]) > tri[i][j + 1]))
            {
                cout << " " << tri[i + 1][j] << " ";
            }
            else if ((tri[i + 1][j] > tri[i + 1][j + 1]) && ((tri[i][j] += tri[i + 1][j]) < tri[i][j + 1]))
            {
                cout << " " << tri[i + 1][j + 1] << " ";
            }
            else if ((tri[i + 1][j] < tri[i + 1][j + 1]) && ((tri[i][j] += tri[i + 1][j + 1]) > tri[i][j + 1]))
            {
                cout << " " << tri[i + 1][j] << " ";
            }
            else
            {
                cout << " " << tri[i + 1][j + 1] << " ";
            }
        }
    }
}

int main()
{
    int tri[A][A] = {{7, 0, 0, 0, 0}, {3, 8, 0, 0, 0}, {8, 1, 0, 0, 0}, {2, 7, 4, 4, 0}, {4, 5, 2, 6, 5}};
    int sum[A][A]={{7, 0, 0, 0, 0}, {3, 8, 0, 0, 0}, {8, 1, 0, 0, 0}, {2, 7, 4, 4, 0}, {4, 5, 2, 6, 5}};
    cout << maxPathsum(tri, 5, 5) << endl;
    SUMPATH(tri,sum,5);
    cout<<endl;
    return 0;
}