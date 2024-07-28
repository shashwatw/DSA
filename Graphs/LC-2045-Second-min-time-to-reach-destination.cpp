//^ https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/

class Solution
{
public:
#define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        unordered_map<int, vector<int>> adj(n + 1);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 1});
        d1[1] = 0;

        while (!pq.empty())
        {
            auto [timePassed, node] = pq.top();
            pq.pop();

            if (d2[n] != INT_MAX && node == n)
            { // We reached n 2nd time means it's the second minimum
                return d2[n];
            }

            int mult = timePassed / change;
            if (mult % 2 == 1)
            {                                     // Red
                timePassed = change * (mult + 1); // to set green
            }

            for (auto &nbr : adj[node])
            {
                if (d1[nbr] > timePassed + time)
                { //+time for this edge to reach nbr
                    d2[nbr] = d1[nbr];
                    d1[nbr] = timePassed + time;
                    pq.push({timePassed + time, nbr});
                }
                else if (d2[nbr] > timePassed + time && d1[nbr] != timePassed + time)
                {
                    d2[nbr] = timePassed + time;
                    pq.push({timePassed + time, nbr});
                }
            }
        }
        return -1;
    }
};

//* SAME method as above diff syntax
class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX), freq(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dist1[1] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int timeTaken = it.first;
            int node = it.second;

            freq[node]++;

            if (freq[node] == 2 && node == n)
                return timeTaken;

            if ((timeTaken / change) % 2)
            {
                timeTaken = change * (timeTaken / change + 1) + time;
            }
            else
            {
                timeTaken = timeTaken + time;
            }

            for (auto neighbor : adj[node])
            {

                if (freq[neighbor] == 2)
                    continue;

                if (dist1[neighbor] > timeTaken)
                {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = timeTaken;
                    pq.push({timeTaken, neighbor});
                }
                else if (dist2[neighbor] > timeTaken && dist1[neighbor] != timeTaken)
                {
                    dist2[neighbor] = timeTaken;
                    pq.push({timeTaken, neighbor});
                }
            }
        }
        return 0;
    }
};

//* BFS Approach
// Approach-2 (Using BFS)
// T.C : O(V + E) - where E = number of edges and V = number of vertices
// S.C : O(V+E)
class Solution
{
public:
#define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);
        queue<P> que;
        que.push({1, 1}); // Visited node 1 once
        d1[1] = 0;

        while (!que.empty())
        {
            auto [node, freq] = que.front();
            que.pop();

            int timePassed = (freq == 1) ? d1[node] : d2[node];
            if (d2[n] != INT_MAX && node == n)
            { // We reached n 2nd time means it's the second minimum
                return d2[n];
            }

            int mult = timePassed / change;
            if (mult % 2 == 1)
            {                                     // Red
                timePassed = change * (mult + 1); // to set green
            }

            for (auto &nbr : adj[node])
            {
                if (d1[nbr] == INT_MAX)
                {
                    d1[nbr] = timePassed + time;
                    que.push({nbr, 1});
                }
                else if (d2[nbr] == INT_MAX && d1[nbr] != timePassed + time)
                {
                    d2[nbr] = timePassed + time;
                    que.push({nbr, 2});
                }
            }
        }
        return -1;
    }
};
