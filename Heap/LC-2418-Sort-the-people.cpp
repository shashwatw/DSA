//^ https://leetcode.com/problems/sort-the-people/description/

//* APPROACH 1
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        priority_queue<pair<int, string>> maxHeap;
        vector<string> ans;

        for (int i = 0; i < heights.size(); i++)
        {
            maxHeap.push({heights[i], names[i]});
        }

        while (!maxHeap.size() == 0)
        {
            string temp = maxHeap.top().second;
            ans.push_back(temp);
            maxHeap.pop();
        }
        return ans;
    }
};

//* APPROACH 2 (without heap)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> A;
        int N = names.size();
        for (int i = 0; i < N; i++)
        {
            A.push_back({heights[i], names[i]});
        }

        sort(A.rbegin(), A.rend());

        vector<string> ans;
        for (int i = 0; i < N; i++)
        {
            ans.push_back(A[i].second);
        }
        return ans;
    }
};