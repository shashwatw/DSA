//* https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-graphs/problem/level-of-nodes1147

class Solution
{
public:
    int bfs(int start, int level, vector<int> adj[], vector<int> vis, int X)
    {
        queue<pair<int, int>> q;
        vis[start] = 1;
        q.push({start, level});

        if (start == X)
            return 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int lvl = q.front().second;
            q.pop();

            lvl++;

            for (auto it : adj[node])
            {
                if (it == X)
                {
                    return lvl;
                }
                else if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, lvl});
                }
            }
        }
        return -1;
    }

    int levelOfX(int V, vector<int> adj[], int X)
    {
        // Code here

        vector<int> vis(V, 0);

        return bfs(0, 0, adj, vis, X);
    }
};
