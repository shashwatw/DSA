//* https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1

class Solution
{
public:
    int countNumberswith4(int n)
    {
        // code here

        int cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            string num = to_string(i);
            for (auto it : num)
            {
                if (it == '4')
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};