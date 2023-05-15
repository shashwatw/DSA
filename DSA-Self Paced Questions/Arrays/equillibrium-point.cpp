#include <iostream>
using namespace std;

void equilibriumPoint(int A[], int n)
{
    int fsum = 0;
    if (n == 1)
    {
        cout << A[0] << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fsum += A[i];
            A[i] = fsum;
        }

        for (int i = 1; i < n; i++)
        {
            if (A[i - 1] == (A[n - 1] - A[i]))
            {
                cout << "Index of eqbrm is: " << i << endl;
            }
        }
    }
}

int main()
{
    int A[] = {1, 5, 5, 4, 2}; // 1 3 6 11 15 17
    int n = sizeof(A) / sizeof(A[0]);

    equilibriumPoint(A, n);
    return 0;
}