//^ https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

//! Approach
//* initially we got the idea of getting shortest cost pTH
//* so we got an idea of implementing dijkstra algo
//* initially we made a min heap PQ of pair form which contains { diff, {row, col }}
//* now we also made a dist matrix and initialised it with infinity or 1e9 and source as 0
//* we started checking pq's top by taking min dist one's pair out first and computing till we get the destination out of the PQ...once we get destination taking out pairs from PQ we return the diff
//* Here at last we write here the condn that if the row and col are the bottom corner most then we have reached the destination
//* we check for validity and check for nodes in all the 4 directions
//* Also we calculate the effort by taking abs value of diff and checking whther it is max than diff(initial one of pair)
//* lastly if we have a diff less than at dist[][] matrix then we push it and write than lesser dist in dist[][] matrix
//* lastly return 0

class Solution
{
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        // code here

        // diff, {row, col}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int row = it.second.first;
            int col = it.second.second;
            int diff = it.first;

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);

                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
