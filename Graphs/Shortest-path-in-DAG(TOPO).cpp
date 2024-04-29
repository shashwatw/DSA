//^ https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

//* INTUITION and ALGO
//* Initially we made an adjacency list to map and store all nodes with their costs
//* Then we found out the topoSort of that graph...which is inside stack
//* Now we will initialise the dist matrix with INT_MAX
//* Now we will iterate over the stack elements and check that what is the min dist from them to its adjacent nodes
//* If the dist in dist[] is greater then we will update it with new dist (less dist) else we will let the dist remain same
//* Finally when the stack is empty we will get the min dist from source to each node in the dist array

//! Better than any other standard algo as topo sort takes less Time complexity...even better than Djiktra's Algo

//& TC- O(N+M)

class Solution
{
private:
    void topoSort(int src, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[src] = 1;

        for (auto it : adj[src])
        {
            int node = it.first;
            int wt = it.second;

            if (!vis[node])
            {
                topoSort(node, adj, vis, st);
            }
        }
        st.push(src);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(N, INT_MAX);
        // make source node's dist as 0
        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v] && dist[node] != INT_MAX)
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        for (auto &d : dist)
        {
            if (d == INT_MAX)
                d = -1;
        }

        return dist;
    }
};