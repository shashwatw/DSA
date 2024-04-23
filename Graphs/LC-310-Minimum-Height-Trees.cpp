//! https://leetcode.com/problems/minimum-height-trees/description/

//^ Reference Video: https://www.youtube.com/watch?v=tJAwo2hgMU8

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> res;

        if (n <= 0)
            return res;

        if (n == 1)
        {
            res.push_back(0);
            return res;
        }

        // make vector for storing degrees
        vector<int> deg(n, 0);
        vector<vector<int>> gr(n);

        for (auto e : edges)
        {
            deg[e[0]]++;
            deg[e[1]]++;

            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }

        // level wise traversal
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            // leaf nodes will have degree as 1
            // To remove them we are checking them and inserting in queue
            if (deg[i] == 1)
                q.push(i);
        }

        // after removing either 1 node will left or 2 nodes
        // so keep removing till we have 2 or 1 nodes left with us
        while (n > 2)
        {
            int sz = q.size();
            n -= sz;

            while (sz > 0)
            {
                int el = q.front();
                q.pop();

                // ne -> neighbours
                for (auto ne : gr[el])
                {
                    deg[ne]--;

                    if (deg[ne] == 1)
                    {
                        q.push(ne);
                    }
                }
                sz--;
            }
        }

        while (!q.empty())
        {
            int el = q.front();
            q.pop();

            res.push_back(el);
        }
        return res;
    }
};