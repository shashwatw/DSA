//^ https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<pair<int, int>>> adj(26);

        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int weight = cost[i];

            adj[u].push_back({v, weight});
        }

        vector<vector<long long>> minConversionCosts(26);

        for (int i = 0; i < 26; i++)
        {
            minConversionCosts[i] = djikstra(i, adj);
        }

        long long totalCost = 0;
        int stringLength = source.length();
        for (int i = 0; i < stringLength; i++)
        {
            if (source[i] != target[i])
            {
                long long charConversionCost =
                    minConversionCosts[source[i] - 'a'][target[i] - 'a'];
                if (charConversionCost == LLONG_MAX)
                {
                    return -1; // Conversion not possible
                }
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }

    vector<long long> djikstra(int src, vector<vector<pair<int, int>>> &adj)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> minCost(26, LLONG_MAX);

        pq.push({0, src});
        minCost[src] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int currCost = it.first;
            int currChar = it.second;

            if (currCost > minCost[currChar])
                continue;

            for (auto neighbor : adj[currChar])
            {
                int targetChar = neighbor.first;
                int conversionCost = neighbor.second;
                long long newTotalCost = currCost + conversionCost;

                if (newTotalCost < minCost[targetChar])
                {
                    minCost[targetChar] = newTotalCost;
                    pq.push({newTotalCost, targetChar});
                }
            }
        }
        return minCost;
    }
};