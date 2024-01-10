// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/max-sum-path-in-two-arrays

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    int max_path_sum(int ar1[], int ar2[], int m, int n)
    {
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0, result = 0;

        while (i < m && j < n)
        {
            if (ar1[i] < ar2[j])
            {
                sum1 += ar1[i++];
            }
            else if (ar1[i] > ar2[j])
            {
                sum2 += ar2[j++];
            }
            else
            { // ar1[i] == ar2[j]
                result += max(sum1, sum2);
                sum1 = 0, sum2 = 0;

                // Handle equal values at the same position
                while (i < m && j < n && ar1[i] == ar2[j])
                {
                    result += ar1[i++];
                    j++;
                }
            }
        }

        // Handle remaining elements if any
        while (i < m)
        {
            sum1 += ar1[i++];
        }

        while (j < n)
        {
            sum2 += ar2[j++];
        }

        // Update result with the remaining sum
        result += max(sum1, sum2);

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        Solution obj;
        int result = obj.max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

// } Driver Code Ends