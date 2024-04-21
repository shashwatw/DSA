//! https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

// User function Template for C++

class Solution
{
public:
    static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.second.second < b.second.second;
    }

    vector<int> maxMeetings(int n, vector<int> &S, vector<int> &F)
    {
        vector<pair<int, pair<int, int>>> arr;
        for (int i = 0; i < n; i++)
        {
            // pair<int, int>p=make_pair(S[i], F[i]);
            arr.push_back({i + 1, {S[i], F[i]}});
        }

        sort(arr.begin(), arr.end(), cmp);
        vector<int> meeting;
        meeting.push_back(arr[0].first);
        // we are storing original indexing in the meeting because after
        // sorting we have lost original meeting index array.
        int ansEnd = arr[0].second.second;

        for (int i = 1; i < n; i++)
        {
            if (arr[i].second.first > ansEnd)
            {
                meeting.push_back(arr[i].first);
                ansEnd = arr[i].second.second;
            }
        }
        sort(meeting.begin(), meeting.end());
        return meeting;
    }
};