//^ https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//* For intuition check Kahn's algo
//* It does not work for Cyclic graph therefore won't be able to produce a V length topo ordering
//* For checking how much length ordering it can produce we have maintained a cnt
//* If it is able to maintain V length topo ordering therefore there does not exists a cycle i.e. return false
//* Else there exists a cycle return true

//& SC - O(N)
//& TC - O(V+E)

//~ CODE using Kahn's(BFS):
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (cnt == V)
            return false;
        else
            return true;
    }
};