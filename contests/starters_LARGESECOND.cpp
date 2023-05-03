#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int high, sechigh;
    while (t--)
    {
        int num;
        cin >> num;
        int arr[100000];

        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + num);
        high = arr[num - 1];

        for (int i = num - 2; i >= 0; i--)
        {
            if (arr[num - 1] != arr[i])
            {
                sechigh = arr[i];
                break;
            }
        }
        int sum = high + sechigh;
        cout << sum << endl;
    }
    return 0;
}
