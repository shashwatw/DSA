#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mean(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << "MEAN: " << floor(sum / n) << endl;
}

int median(int a[], int n)
{
    sort(a, a + n);
    if (n % 2 == 1)
    {
        cout << "MEDIAN: " << floor(a[n / 2]) << endl;
    }
    else
    {
        cout << "MEDIAN: " << floor((a[(n - 1) / 2] + (a[(n - 1) / 2 + 1])) / 2) << endl;
    }
}

int main()
{
    int a[] = {1, 2, 19, 28, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    mean(a, n);
    median(a, n);
}