// https://www.geeksforgeeks.org/problems/minimize-the-difference/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        int miniLeft = INT_MAX;
        int maxiLeft = INT_MIN;
        deque<int> maxiRight;
        deque<int> miniRight;
        for (int i = k; i < n; i++)
        {
            if (maxiRight.empty())
            {
                maxiRight.push_back(i);
                miniRight.push_back(i);
            }
            else
            {
                while (!maxiRight.empty() and arr[maxiRight.back()] <= arr[i])
                {
                    maxiRight.pop_back();
                }
                maxiRight.push_back(i);

                while (!miniRight.empty() and arr[miniRight.back()] >= arr[i])
                {
                    miniRight.pop_back();
                }
                miniRight.push_back(i);
            }
        }
        int diff = INT_MAX;
        for (int i = 0; i <= n - k; i++)
        {
            int mini = min(miniLeft, arr[miniRight.front()]);
            int maxi = max(maxiLeft, arr[maxiRight.front()]);
            diff = min(diff, maxi - mini);
            miniLeft = min(miniLeft, arr[i]);
            maxiLeft = max(maxiLeft, arr[i]);
            // i-->i+k-1
            if (maxiRight.front() == i + k)
            {
                maxiRight.pop_front();
            }
            if (miniRight.front() == i + k)
            {
                miniRight.pop_front();
            }
            if (maxiRight.empty())
            {
                diff = min(diff, maxiLeft - miniLeft);
                break;
            }
        }
        return diff;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int k;
        scanf("%d", &k);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends