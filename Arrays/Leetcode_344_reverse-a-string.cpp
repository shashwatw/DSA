class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        int n = s.size();
        int strt = 0;
        int end = n - 1;

        while (strt < end)
        {
            swap(s[strt++], s[end--]);
        }
    }
};