#include <iostream>
using namespace std;
int main()
{

    // int even[6] = {2, 4, 6, 8, 10, 12};
    int odd[5] = {1, 3, 5, 7, 9};

    int key;
    cout << "Enter the key: " << endl;
    cin >> key;

    // int n = sizeof(even) / sizeof(even[0]);
    int n = sizeof(odd) / sizeof(odd[0]);

    int l = 0;
    int h = n - 1;

    while (l <= h)
    {

        int mid = (l + h) / 2;

        // if (even[mid] == key)
        if (odd[mid] == key)
        {
            cout << "Found at " << mid + 1 << " Position !" << endl;
            return mid;
        }
        else if (odd[mid] > key)
        // else if (even[mid] > key)
        {
            h = mid - 1;
        }
        // else if (even[mid] < key)
        else if (odd[mid] < key)
        {
            l = mid + 1;
        }
    }

    cout << "Not Found !" << endl;
    return 0;
}