#include <iostream>
using namespace std;
// optional params always start from right to left
//  n can't be optional if start is  not optional as right to left
void print(int arr[], int n, int start = 0)
{

    for (int i = start; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{

    int arr[5] = {1, 4, 7, 8, 9};
    int size = 5;

    print(arr, size);
    cout << endl;
    print(arr, size, 2);

    return 0;
}