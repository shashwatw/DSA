// https://www.naukri.com/code360/problems/median-in-a-stream_975268

// Reference Video:
// https://www.youtube.com/watch?v=RrxpTWqj97A

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
//! 1) maxHeap for left elements.
//! 2) minHeap for right elements.

// we are using a signum function to tell which case it is.

#include <queue>
#include <limits>

int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

void callMedian(int element, priority_queue<int> &maxHeap,
                priority_queue<int, vector<int>, greater<int>> &minHeap, int &median)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    case 0:
        if (element > median)
        {
            // max heap size -> n.......min heap size -> n wala case....so koi na koi beech ek
            // element hi ans hoga...maybe max of first half or min of second
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;

    case 1:
        if (element > median)
        {
            // max heap size -> n.......min heap size -> n-1 wala case
            // to insert in max heap we habe to pop maxheap element and push to minheap
            // taki dono ke size ka diff 1 hi rahe

            // yaha we are pushing in minheap as it is left of median and this element
            // is greater than median so will go left side
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;

    case -1:
        if (element > median)
        {
            // max heap size -> n-1.......min heap size -> n wala case
            // can directly insert in maxheap kyuki diff will be 0 but
            // minheap mein agar element dalna h toh minheap se ek
            // maxheap mein dalna hoga
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    // Write your code here
    int median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
