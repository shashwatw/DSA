//* https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

class Solution
{
private:
    bool isPalindrome(string &res)
    {
        int i = 0;
        int j = res.size() - 1;

        while (i < j)
        {
            if (res[i] != res[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    string pattern(vector<vector<int>> &arr)
    {
        // Code Here
        int row = arr.size();
        int col = arr[0].size();
        string res;
        string tempAns;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tempAns.push_back(arr[i][j] + '0');
            }
            if (isPalindrome(tempAns))
            {
                res = to_string(i) + " R";
                return res;
            }
            tempAns = "";
        }

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                tempAns.push_back(arr[j][i] + '0');
            }
            if (isPalindrome(tempAns))
            {
                res = to_string(i) + " C";
                return res;
            }
            tempAns = "";
        }

        return "-1";
    }
};