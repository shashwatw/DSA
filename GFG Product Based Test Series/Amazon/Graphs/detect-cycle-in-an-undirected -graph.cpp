//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/detect-cycle-in-an-undirected-graph

class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool detect(int source, vector<int> adj[], int vis[])
    {
        vis[source] = 1;

        queue<pair<int, int>> q; // node, parent

        q.push({source, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else
                {
                    if (parent != it)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};