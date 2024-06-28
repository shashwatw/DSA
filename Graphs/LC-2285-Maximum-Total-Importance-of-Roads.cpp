//* https://leetcode.com/problems/maximum-total-importance-of-roads/description/

class CompareVector
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] > b[0]; // Compare based on the first element
    }
};

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        priority_queue<vector<int>, vector<vector<int>>, CompareVector> pq;
        vector<long long> indegree(n, 0);

        for (auto it : roads)
        {
            pq.push(it);
        }

        while (!pq.empty())
        {
            vector<int> topEl = pq.top();
            indegree[topEl[0]]++;
            indegree[topEl[1]]++;
            pq.pop();
        }

        sort(indegree.begin(), indegree.end());

        long long importance = 0;
        for (int i = 0; i < indegree.size(); i++)
        {
            importance += indegree[i] * (i + 1);
        }
        return importance;
    }
};