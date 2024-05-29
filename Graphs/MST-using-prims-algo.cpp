//! https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

//^ Approach (Greedy Intuition)

//* Initially we craeted a min heap of pair format {wt, node}
//* now push {0,0} as initial configuration
//* create visited vector and initialise it with 0
//* after pushing in pq.... run a while loop till pq is not empty
//* check if the node is already vis...skip to next iteration
//* If not then add its weight to MST sum, and then check for its adjacent Nodes
//* if adjacent nodes are not visited, then push them along with their edge weights in pq

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;

            // add it to MST
            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];

                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};