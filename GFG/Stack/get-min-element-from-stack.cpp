// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-stacks/problem/get-minimum-element-from-stack

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

#include <stack>

class Solution
{
    int minEle;
    stack<int> s;

public:
    int getMin()
    {
        if (s.empty())
            return -1;
        else
            return minEle;
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        int t = s.top();
        s.pop();

        if (t < minEle)
        {
            int oldMinEle = minEle;
            minEle = 2 * minEle - t;
            return oldMinEle;
        }
        else
        {
            return t;
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            return;
        }

        if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
        {
            s.push(x);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        Solution ob;
        while (q--)
        {
            int qt;
            cin >> qt;
            if (qt == 1)
            {
                // push
                int att;
                cin >> att;
                ob.push(att);
            }
            else if (qt == 2)
            {
                // pop
                cout << ob.pop() << " ";
            }
            else if (qt == 3)
            {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends