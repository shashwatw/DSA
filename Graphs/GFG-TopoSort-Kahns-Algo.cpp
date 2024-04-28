//^ https://practice.geeksforgeeks.org/problems/topological-sort/1

//! Intuition
//* Firstly we made an array of indegree where we stores indegree by just inc wherever we get adj[node]
//* Now we initially pushed 0 indegree ones in the queue created
//* While popping we push them into topo vector to get the linear ordering
//* Now we decrement indegree of the adjacent nodes of popped element and check if anyone's indegree got 0
//* If yes then push in q else move forward
//* When the queue is empty we get a linear topo ordering inside our topo vector

//& TC - O(V+E)
//& SC - O(2N) = O(N)

//~ CODE (BFS)
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
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
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};