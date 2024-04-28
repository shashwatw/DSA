//^ https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//! INTUITION
//* First we ensured that every node is visited from the graph
//* Then we made two arrays to keep a track of visited and pathVisited
//* we called dfs and made both vis and pathVis of that node as 1
//* While returning we make the pathVis again back to 0
//* From visited array we keep track that we have earlier travelled or not and if visited we check that it's pathVisited is not 1
//* If its 1 and we are reaching pathVis again that means there exists a directed cycle hence return true
//* Else return false

//& TC - O(V+E) {due to directed graph}
//& SC - O(2N)

//~ CODE (DFS):
class Solution
{
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            // if not visited call dfsCheck for it
            if (!vis[adjacentNode])
            {
                if (dfsCheck(adjacentNode, adj, vis, pathVis) == true)
                    return true;
            }

            // if pathVis is also marked 1 then we have encountered a loop
            else if (pathVis[adjacentNode] == true)
            {
                return true;
            }
        }

        // while returning to prev dfs call make pathVis[node] as 0
        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};

        // if any node is left unvisited ensure each one gets visited
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
        return false;
    }
};