//* https://leetcode.com/problems/find-center-of-star-graph/

//^ TC - O(1) SC - O(1)

// We only need to check any two edges in the list. The common node between these edges is guaranteed to be the center. This works because, in a star graph with N-1 edges, only the center node has a degree greater than 1.

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        // Extract the first two edges
        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];

        // The center node will be the one that appears in both edges
        if (a == c || a == d)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
};
