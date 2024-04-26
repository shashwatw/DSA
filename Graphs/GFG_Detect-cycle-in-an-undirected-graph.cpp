//^ https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//* INTUITION
//* Firstly in the main function we ran a loop for checking for dusconnected graphs too.
//* in the detect cycle functionality we will give the src i.e. source and push in a queue which has the source node and its parent
//* Initially No parent will be there for source so it'll be -1
//* Now we will go for bfs and till q is empty we traverse and vis all adjacent unvisited nodes of source node
//* When we visit a already visited node we will check that whether that node is not a paarent of source node
//* If it is then do not consider a loop else consider a loop

class Solution
{
private:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (adjacentNode != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};