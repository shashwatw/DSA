// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-stacks/problem/sort-a-stack

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}
// } Driver Code Ends

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertAtCorrectPosition(stack<int> &s, int x)
{
    if (s.empty() || x < s.top())
    {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtCorrectPosition(s, x);

    s.push(temp);
}

void SortedStack::sort()
{
    stack<int> tempStack;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        insertAtCorrectPosition(tempStack, x);
    }

    // Copy elements back to the original stack
    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
