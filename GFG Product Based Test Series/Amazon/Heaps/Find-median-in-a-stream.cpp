// s-bundle/track/amazon-heap/problem/find-median-in-a-stream-1587115620

// Reference Video:
// https://www.youtube.com/watch?v=RrxpTWqj97A
//! To see above implementation go to -----> https://www.naukri.com/code360/problems/median-in-a-stream_975268
// Approach 1 : Insertion Sort (why ? because running stream...so we can directly insert new element which came in array)
// logic of median is for odd array - n/2 element
// for even array - avg of 2 mid elements
//  TC of 1st Approach - O(n^2);

//******************OPTIMAL APPROACH***********************
// using min and max heaps

// we will assume that there exists a median
// Now two cases are possible
// whether if arr size is odd -> median is mid element...therefore elements to left and right both of median are m;

// For even case
// case 1: elements right to median -> n & elements left to median -> n-1
// so median will be mid 2 elements' avg
// To get that we are maintaing
// 1) maxHeap for left elements.
// 2) minHeap for right elements.

// we are using a signum function to tell which case it is.

//! ******************************************* Back to Main solution for GFG**********************************************

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Function to insert heap.

    int signum(int a, int b)
    {
        if (a == b)
            return 0;
        else if (a > b)
            return 1;
        else
            return -1;
    }

    void insertHeap(int &x)
    {
        switch (signum(maxHeap.size(), minHeap.size()))
        {
        case 0:
            if (x > median)
            {
                minHeap.push(x);
                median = minHeap.top();
            }
            else
            {
                maxHeap.push(x);
                median = maxHeap.top();
            }
            break;

        case 1:
            if (x > median)
            {
                minHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2.00;
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2.00;
            }
            break;

        case -1:
            if (x > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2.00;
            }
            else
            {
                maxHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2.00;
            }
            break;
        }
    }

    // Function to return Median.
    double getMedian()
    {
        return median;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends