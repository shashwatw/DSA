//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/mother-vertex

class Solution
{
public:
    // Function to find a Mother Vertex in the Graph.

    bool dfs(int src, vector<int> adj[], vector<bool> &vis, int &nums)
    {
        vis[src] = true;
        nums++;

        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, nums);
            }
        }

        return nums == vis.size();
    }

    int findMotherVertex(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        int lastFinishedVertex = 0;

        // Perform DFS to find the last finished vertex
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                int nums = 0;
                dfs(i, adj, vis, nums);
                lastFinishedVertex = i;
            }
        }

        // Check if the last finished vertex is a mother vertex
        fill(vis.begin(), vis.end(), false); // fill with false values initially
        int nums = 0;
        if (dfs(lastFinishedVertex, adj, vis, nums))
        {
            return lastFinishedVertex;
        }

        return -1;
    }
};