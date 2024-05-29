//^ https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

//! APPROACH
//* Initially we have made a graph i.e adj list to store the nodes of undirected graph
//* We have used a pair of int, int form of priority queue to store {dist, node}
//* Up next we maintained two vectors dist initialised with INT_MAX and ways with 0
//* dist[0] is 0 and ways[0] is 1
//* we pushed {0,0} in the PQ
//* started while loop till pq gets empty
//* checks for each adjacent node and checks whether dis + edW is lesser than present dist in dist array
//* if lesser
//* Update ways as the ways to reach the prev node and update the new distance in dist array
//* also push the adjnode in PQ along with the distance
//* If the new dist comes out same then update the ways and do modulo
//* finally at last return value at dist[n-1] % mod

// User function Template for C++

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // code here
        vector<pair<int, int>> adj[n];

        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 2e9);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};