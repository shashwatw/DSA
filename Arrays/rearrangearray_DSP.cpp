#include <iostream>
#include <vector>

using namespace std;

void rearrangeArray(vector<int> &arr)
{
    int n = arr.size();

    // Modifying the array elements to encode new values
    for (int i = 0; i < n; i++)
    {
        arr[i] += (arr[arr[i]] % n) * n;
    }

    // Decoding the new values to get the rearranged array
    for (int i = 0; i < n; i++)
    {
        arr[i] /= n;
    }
}

void printArray(const vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N = 5;
    vector<int> arr = {4, 0, 2, 1, 3};

    cout << "Original array: ";
    printArray(arr);

    rearrangeArray(arr);

    cout << "Rearranged array: ";
    printArray(arr);

    return 0;
}
