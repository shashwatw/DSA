//^https://leetcode.com/problems/find-eventual-safe-states/description/

//! INTUITION
//* What we did here is same as we did in detect a cycle in directed graph using dfs (prerequisite)
//* Now here additionally we are maintaing a check array which as and when loop is detected will make all the nodes of the loop wala path as 0 (check[node] = 0)
//* If successfully there is no loop from a node we make those nodes as check[node] = 1;
//* Finally in the check all the indices that have 1 will be pushed back to safeNode vector as they are safeNodes
//* Return the safeNodes

//~ CODE using DFS:
class Solution
{
private:
    bool dfsCheck(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjacentNode : graph[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfsCheck(adjacentNode, graph, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true; // cycle found i.e. unsafe state
                }
            }
            else if (pathVis[adjacentNode])
            {
                check[node] = 0;
                return true; // cycle found i.e. unsafe state
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        vector<int> check(V, 0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};