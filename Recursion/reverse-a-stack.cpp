//* https://www.geeksforgeeks.org/problems/reverse-a-stack/1

// User function Template for C++

class Solution
{
public:
    void insert(stack<int> &s, int ele)
    {
        if (s.size() == 0)
        {
            s.push(ele);
            return;
        }

        int temp = s.top();
        s.pop();

        insert(s, ele);

        s.push(temp);
    }

    void Reverse(stack<int> &s)
    {
        if (s.size() == 0 || s.size() == 1)
            return;

        int temp = s.top();
        s.pop();

        Reverse(s);

        insert(s, temp);
    }
};