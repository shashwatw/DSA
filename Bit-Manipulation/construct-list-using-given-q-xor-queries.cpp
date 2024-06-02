//* https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

//^ Brute Approach

class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> ans;
        ans.push_back(0);

        for (auto it : queries)
        {
            int op = it[0];
            int num = it[1];

            if (op == 0)
            {
                ans.push_back(num);
            }
            else
            {
                for (int j = 0; j < ans.size(); j++)
                {
                    ans[j] = ans[j] ^ num;
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

//^ APPROACH Optimal ;
class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> ans;
        int totXor = 0;

        reverse(queries.begin(), queries.end());

        for (auto it : queries)
        {
            int op = it[0];
            int num = it[1];

            if (op == 0)
            {
                ans.push_back(num ^ totXor);
            }
            else
            {
                totXor ^= num;
            }
        }
        ans.push_back(0 ^ totXor);
        sort(ans.begin(), ans.end());
        return ans;
    }
};