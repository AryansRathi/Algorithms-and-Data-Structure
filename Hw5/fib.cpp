/*
CH-231-A
a5 p1.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

int naive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return naive(n - 1) + naive(n - 2);
    }
}
int bottom_up(int n)
{
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
int closed_up(int n)
{
    return round(pow(((1 + sqrt(5)) / 2), n) / sqrt(5));
}
int matrix(int n)
{
    int arr[2][2];
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    int mul[2][1];
    int a, b;
    a = mul[0][0] = 0;
    b = mul[1][0] = 1;
    for (int i = 0; i < n; i++)
    {
        a = mul[0][0];
        b = mul[1][0];
        mul[0][0] = arr[0][0] * a + arr[0][1] * b;
        mul[1][0] = arr[1][0] * a + arr[1][1] * b;
    }
    return mul[0][0];
}
int main()
{
    float time_taken;
    time_t fixed = 1.0;
    clock_t begin, end;

    int value = 1;
    ofstream file1;
    file1.open("Naive.txt");
    do
    {
        begin = clock();
        naive(value);
        end = clock();
        time_taken = (float)(end - begin) / CLOCKS_PER_SEC;
        file1 << value << " " << time_taken << endl;
        value = value + 10;
    } while (time_taken < fixed);

    ofstream file2;
    file2.open("Bottom.txt");
    do
    {
        begin = clock();
        bottom_up(value);
        end = clock();
        time_taken = (float)(end - begin) / CLOCKS_PER_SEC;
        file2 << value << " " << time_taken << endl;
        value = value + 10;
    } while (time_taken < fixed);

    ofstream file3;
    file3.open("Closed.txt");
    do
    {
        begin = clock();
        closed_up(value);
        end = clock();
        time_taken = (float)(end - begin) / CLOCKS_PER_SEC;
        file3 << value << " " << time_taken << endl;
        value = value + 10;
    } while (time_taken < fixed);

    ofstream file4;
    file4.open("Matrix.txt");
    do
    {
        begin = clock();
        matrix(value);
        end = clock();
        time_taken = (float)(end - begin) / CLOCKS_PER_SEC;
        file4 << value << " " << time_taken << endl;
        value = value + 10;
    } while (time_taken < fixed);
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    return 0;
}
//References
//mathonline.wikidot.com/a-closed-form-of-the-fibonacci-sequence
//www.geeksforgeeks.org/program-for-nth-fibonacci-number/