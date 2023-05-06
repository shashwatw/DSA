#include <iostream>
using namespace std;
// 2D Arrays
bool isPresent(int arr[][4], int target, int row, int col)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
                return true;
        }
    }
    return false;
}

void printColSum(int arr[][4], int row, int col)
{
    cout << "Column Sum: ";

    for (int col = 0; col < 4; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void printRowSum(int arr[][4], int row, int col)
{
    cout << "Row Sum: ";

    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int main()
{
    int arr[3][4];

    // taking input -> row wise input

    cout << "Enter the elements of the array: " << endl;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }

    /*
    // taking input -> col wise input
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            cin >> arr[row][col];
        }
    }
*/
    // printing output -> row wise output
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    if (isPresent(arr, target, 3, 4))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }

    printColSum(arr, 3, 4);
    printRowSum(arr, 3, 4);

    return 0;
}