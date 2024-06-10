// *https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

// User function template for C++
class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        // code here
        sort(nuts, nuts + n);
        sort(bolts, bolts + n);
    }
};