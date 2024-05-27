//*https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/bfs-traversal-of-graph

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        bool vis[V] = {false};
        vis[0] = true;
        queue<int> q;
        q.push(0);
        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};