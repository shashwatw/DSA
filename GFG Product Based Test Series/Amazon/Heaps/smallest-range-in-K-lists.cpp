// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-heap/problem/find-smallest-range-containing-elements-from-k-lists

// Reference:
// https://www.youtube.com/watch?v=RrxpTWqj97A

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class node
{
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        pair<int, int> p;
        priority_queue<node *, vector<node *>, compare> minHeap;
        int maxi = INT_MIN, mini = INT_MAX;

        // create min heap
        for (int i = 0; i < k; i++)
        {
            int element = KSortedArray[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);

            minHeap.push(new node(element, i, 0));
        }

        int start = mini;
        int end = maxi;

        while (!minHeap.empty())
        {
            node *temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;

            // range or anser updation
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            // next element exists
            if (temp->col + 1 < n)
            {
                maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]);
                minHeap.push(new node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else
            {
                break;
            }
        }
        p.first = start;
        p.second = end;
        return p;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends