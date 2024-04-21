//! https://geeksforgeeks.org/problems/activity-selection-1587115620/1

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        int cnt = 1;

        int endTime = v[0].second;

        for (int i = 1; i < n; i++)
        {
            if (v[i].first > endTime)
            {
                cnt++;
                endTime = v[i].second;
            }
        }
        return cnt;
    }
};