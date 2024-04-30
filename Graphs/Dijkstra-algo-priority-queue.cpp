//^ https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//* INTUITION
//* Here i just made a pq of min heap to store and take top element with least distance
//* Its basically similar to other algos
//* Go through code

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // creating min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[S] = 0;

        pq.push({0, S}); //{ node , weight }

        while (!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (distance + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};