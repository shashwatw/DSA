//^ https://www.geeksforgeeks.org/problems/alien-dictionary/1

//! Intuition
//* Out motive is to find the alien dictionary order
//* What we are thinking is we can take 2-2 pairs of strings and compare each char of them from the beginning till someone gets mismatched
//* Once it mismatches we will add them in the adjacency list and make a directed graph's adj list through it
//* After this we can simply call plain topo sort for it to get the alien order

//& CODE :
class Solution
{
private:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);

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

public:
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<vector<int>> adj(K);

        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.size(), s2.size());

            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string res = "";

        for (auto it : topo)
        {
            res += char(it + 'a');
        }

        return res;
    }
};