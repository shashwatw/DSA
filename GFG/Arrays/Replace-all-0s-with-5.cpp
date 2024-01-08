// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/replace-all-0s-with-5

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends

/*you are required to complete this method*/
int convertFive(int n)
{
    string num = to_string(n);

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '0')
        {
            num[i] = '5';
        }
    }

    return stoi(num);
}