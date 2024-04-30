//^ https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//* INTUITION
//* Check for dijkstra using priority queue it's similar approach

//& Can't say this method is better than PQ or vice versa as it lessens the iterations of set by erasing but erase has logarithmic time complexity.

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;

        vector<int> dist(V, INT_MAX);

        dist[S] = 0;

        st.insert({0, S});

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeW = it[1];

                if (dis + edgeW < dist[adjNode])
                {
                    if (dist[adjNode] != INT_MAX)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};