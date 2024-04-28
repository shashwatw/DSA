//^ https://leetcode.com/problems/course-schedule-ii/description/

//* INTUITION
//* Go back and watch course schedule 1 and topo sort using Kahn's

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> adj(numCourses);

        for (auto prereq : prerequisites)
        {
            adj[prereq[1]].push_back(prereq[0]);
        }

        vector<int> indegree(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            topo.push_back(course);

            for (auto dependentCourses : adj[course])
            {
                indegree[dependentCourses]--;
                if (indegree[dependentCourses] == 0)
                    q.push(dependentCourses);
            }
        }

        if (topo.size() == numCourses)
            return topo;
        else
            return {};
    }
};