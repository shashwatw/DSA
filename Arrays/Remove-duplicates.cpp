//^ https://www.geeksforgeeks.org/problems/remove-duplicates3034/1

// User function template for C++
class Solution
{
public:
    string removeDups(string str)
    {
        // Your code goes here
        vector<bool> alphas(26, false);

        string res;
        for (auto it : str)
        {
            if (alphas[it - 'a'] == false)
            {
                alphas[it - 'a'] = true;
                res.push_back(it);
            }
        }
        return res;
    }
};