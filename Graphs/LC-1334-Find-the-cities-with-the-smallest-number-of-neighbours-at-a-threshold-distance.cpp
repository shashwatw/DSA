//^ https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution
{
private:
    void dijkstra(int n, vector<vector<pair<int, int>>> &adj, int src, vector<int> &dist)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &edge : adj[node])
            {
                int adjNode = edge.first;
                int edgeWeight = edge.second;

                if (distance + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        int city = -1, minReachableCities = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            vector<int> dist(n, INT_MAX);
            dijkstra(n, adj, i, dist);

            int reachableCities = 0;
            for (int j = 0; j < n; ++j)
            {
                if (dist[j] <= distanceThreshold)
                {
                    ++reachableCities;
                }
            }

            if (reachableCities <= minReachableCities)
            {
                minReachableCities = reachableCities;
                city = i;
            }
        }

        return city;
    }
};
