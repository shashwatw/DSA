//! https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// Refer to notes for more clear explanation

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meets;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            meets.push_back(p);
        }

        sort(meets.begin(), meets.end(), cmp);

        int cnt = 1;
        int meetEnd = meets[0].second;

        for (int i = 1; i < n; i++)
        {
            if (meets[i].first > meetEnd)
            {
                cnt++;
                meetEnd = meets[i].second;
            }
        }
        return cnt;
    }
};