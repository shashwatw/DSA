//^ https://practice.geeksforgeeks.org/problems/topological-sort/1

//* Linear orderung of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
//* For only DAGs

//! INTUTION
//* Here we are initially checking for disconnected components and then calling dfs for unvisited one
//* In the dfs call we are going to each and every node till they have nothing further and we push them in bottom up appraoch in stack
//* Lastly we pop the stack and get the correct linear ordering

//& SC = O(N) + O(N) = O(N)
//& TC = O(V+E)

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                dfs(adjacentNode, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};