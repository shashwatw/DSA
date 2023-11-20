// https://leetcode.com/problems/number-of-provinces/description/

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &visit)
    {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[node][i] && !visit[i])
            {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        int numComp = 0;
        vector<bool> visit(V);

        for (int i = 0; i < V; i++)
        {
            if (!visit[i])
            {
                numComp++;
                dfs(i, isConnected, visit);
            }
        }

        return numComp;
    }
};