//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/depth-first-traversal-for-a-graph

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        vector<int> ans;

        dfs(0, adj, vis, ans); // start DFS from node 0
        return ans;
    }

    void dfs(int start, vector<int> adj[], vector<bool> &vis, vector<int> &ans)
    {
        vis[start] = true;
        ans.push_back(start);

        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, ans);
            }
        }
    }
};