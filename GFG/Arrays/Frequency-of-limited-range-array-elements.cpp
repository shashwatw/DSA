// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/frequency-of-array-elements-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        {
            for (int i = 0; i < N; i++)
            {
                arr[i] = arr[i] - 1;
                // subtracting -1 from all the numbers just to ease the calculation process
            }
            // so now my numbers are in between 0 to P-1 in the array
            for (int i = 0; i < N; i++)
            {
                // finding the original number at every index

                if (arr[i] % P < N)
                {
                    // if that number is greater than N then ignore the number else add P to the number since
                    // all the numbers are less than P so upon module operation we get the original number back.
                    arr[arr[i] % P] += P;
                }
            }
            for (int i = 0; i < N; i++)
            {
                if (arr[i] / P == 0)
                {
                    // if arr[i]/P is 0 that means no occurrence for the number i.e. arr[i] was present
                    // so no P was added to that arr index value.
                    arr[i] = 0;
                }
                else
                {
                    arr[i] /= P;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    // testcases
    cin >> t;

    while (t--)
    {

        int N, P;
        // size of array
        cin >> N;

        vector<int> arr(N);

        // adding elements to the vector
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> P;
        Solution ob;
        // calling frequncycount() function
        ob.frequencyCount(arr, N, P);

        // printing array elements
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends