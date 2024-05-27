//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/detect-cycle-in-a-directed-graph

class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool dfs(int start, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[start] = 1;
        pathVis[start] = 1;

        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pathVis) == true)
                {
                    return true;
                }
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[start] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};