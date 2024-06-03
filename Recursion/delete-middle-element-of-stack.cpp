//* https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

// User function template for C++

class Solution
{
public:
    // Function to delete middle element of a stack.

    void solve(stack<int> &s, int k)
    {
        if (k == 1)
        {
            s.pop();
            return;
        }

        int temp = s.top();
        s.pop();

        solve(s, k - 1);

        s.push(temp);
    }
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        // code here..
        if (sizeOfStack == 0)
            return;

        int k = sizeOfStack / 2 + 1;

        solve(s, k);
    }
};