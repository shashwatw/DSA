//^ https://practice.geeksforgeeks.org/problems/number-of-provinces/1

//* APPROACH 1 - Using dfs/bfs basic

// SC - O(n) + O(n);
// TC - O(n) + O(V+2E) {nearly linear TC}

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here

        // change adjacency matrix to list
        vector<int> adjLs[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends

//* LEETCODE - Striver Approach (DFS)

//& by DFS, humne first adjacency matrix ko convert kiya in adjacency list
//& then we have made a new vis vector.
//& when disconnection is obtained we will call dfs and also increment a counter to track disconnections
//& Return counts as final they are the total disconnections or provinces obtained

//~ Space complexity - O(n) + O(n)  (Vis array and worst case recur. stack space....ignoring adjacency list space)
//~ Time Complexity - O(n) + O(V + 2E)  (n for the for loop and inside we are calling dfs in total n times only
//~ as we are checking for if its visited or not and in total n dfs calls there fore O(V+2E) )

//! TC - O(n)  SC  -  O(n)

class Solution
{
public:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis)
    {
        vis[node] = 1;

        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected[0].size();

        vector<int> adjLs[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

//* LEETCODE - Striver Approach (BFS)
class Solution
{
public:
    void bfs(int start, vector<int> adjLs[], vector<int> &vis)
    {
        queue<int> q;
        q.push(start);
        vis[start] = 1; // Mark the starting node as visited

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Traverse all neighbors of the current node
            for (int neighbor : adjLs[node])
            {
                // If the neighbor is not visited, mark it as visited and add it to the queue
                if (!vis[neighbor])
                {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected[0].size();

        vector<int> adjLs[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

//* APPROACH 2 (using disjoint set) - refer disjoint set first

class DisjointSet
{

public:
    vector<int> rank, parent, size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.parent[i] == i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};