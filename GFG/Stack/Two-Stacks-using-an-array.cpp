// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-stacks/problem/implement-two-stacks-in-an-array

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class twoStacks
{
public:
    int *arr;
    int size;
    int top1, top2;

    twoStacks()
    {
        size = 200;
        arr = new int[size];
        top1 = size / 2 + 1;
        top2 = size / 2;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 > 0)
        {
            top1--;
            arr[top1] = x;
        }
        else
        {
            return;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top2 < size - 1)
        {
            top2++;
            arr[top2] = x;
        }
        else
        {
            return;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 <= size / 2)
        {
            int x = arr[top1++];
            return x;
        }
        else
        {
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 >= size / 2 + 1)
        {
            int x = arr[top2--];
            return x;
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

    int T;
    cin >> T;
    while (T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1)
            {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            }
            else if (QueryType == 2)
            {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends