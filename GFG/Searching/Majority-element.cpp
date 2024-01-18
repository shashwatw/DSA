// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-searching/problem/majority-element-1587115620

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // Moore's Voting Algorithm
        int count = 1;
        int majority = a[0];

        if (size == 1)
        {
            return a[0];
        }

        for (int i = 1; i < size; i++)
        {
            if (a[i] == majority)
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    majority = a[i];
                }
                else if (count == 1)
                {
                    majority = a[i];
                }
                else
                {
                    count--;
                }
            }
        }

        int flag = 0;

        for (int i = 0; i < size; i++)
        {
            if (majority == a[i])
            {
                flag++;
            }
        }

        if (flag > size / 2)
        {
            return majority;
        }
        else
        {
            return -1;
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
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends