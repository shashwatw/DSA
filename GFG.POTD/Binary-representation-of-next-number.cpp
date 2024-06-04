//*https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        // code here.
        int i = 0;
        int cnt = 0;

        // remove leading zeroes
        while (s[i] == '0')
        {
            cnt++;
            i++;
        }
        s = s.substr(cnt);

        bool flag = false;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                flag = true;
                s[i] = '1';
                break;
            }
            else
            {
                s[i] = '0';
            }
        }

        if (flag == false)
        {
            s = '1' + s;
        }

        return s;
    }
};