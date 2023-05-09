// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {

        int i = 0;
        int j = n - 1;
        int k = 0;

        while (k <= j)
        {
            if (a[k] == 0)
            {
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
                i++;
                k++;
            }
            else if (a[k] == 1)
            {
                k++;
            }
            else if (a[k] == 2)
            {
                int temp = a[j];
                a[j] = a[k];
                a[k] = temp;
                j--;
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends