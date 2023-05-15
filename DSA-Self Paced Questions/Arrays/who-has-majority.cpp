#include <iostream>
using namespace std;

void majority(int arr[], int n, int x, int y)
{
    int countx = 0, county = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            countx++;
        }
        else if (arr[i] == y)
        {
            county++;
        }
    }

    if (countx > county)
    {
        cout << x << endl;
    }
    else if (countx == county)
    {
        if (x > y)
        {
            cout << y << endl;
        }
        else
        {
            cout << x << endl;
        }
    }
    else
    {
        cout << y << endl;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    int y = 7;

    majority(arr, n, x, y);

    return 0;
}