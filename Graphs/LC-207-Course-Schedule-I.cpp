//^https://leetcode.com/problems/course-schedule/description/

//* INTUITION
//* We first built the adjacency list for the prerequisite and independent courses
//* Now we did same as detect a cycle in topo sort with Kahns

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // create an adjacency list according to prerequisites and courses
        vector<vector<int>> adj(numCourses);

        for (auto prereq : prerequisites)
        {
            adj[prereq[0]].push_back(prereq[1]);
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
                q.push(i);
        }

        int cnt = 0;
        while (!q.empty())
        {
            int courses = q.front();
            q.pop();
            cnt++;

            for (auto dependentCourses : adj[courses])
            {
                indegree[dependentCourses]--;
                if (indegree[dependentCourses] == 0)
                    q.push(dependentCourses);
            }
        }

        return cnt == numCourses;
    }
};