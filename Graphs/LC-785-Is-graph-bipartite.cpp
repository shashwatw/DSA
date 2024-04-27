//^ https://leetcode.com/problems/is-graph-bipartite/description/

//! INTUITION
//* We are first checking for disconnected components and that's why running a loop to check and run for any node which is left unvisited
//* Now in our check function we are using BFS
//* Initially we are making the color of start node as 0...Note that we are using 0 and 1 as two diff colours to color the graph
//* Pushing the starting node in the queue
//* now popping the queue according to FIFO and pushing its neighbours but before pushing we are checking two things
//*     1. If they are not visited colour them of opp color of its neighbour
//*     2. if they are coloured they should have opp color of the their neightbour if not then return false
//* If whole while loop euns and queue gets empty that means we were able to colour all the nodes of the graph with 2 colours and no adjacent node have same colour
//* Then its a bipartite graph and return true

//& APPROACH USING BFS

class Solution
{
private:
    bool check(int start, int V, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int adjacentNode : graph[node])
            {
                if (color[adjacentNode] == -1)
                {
                    color[adjacentNode] = !color[node];
                    q.push(adjacentNode);
                }
                else if (color[adjacentNode] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; ++i)
        {
            if (color[i] == -1)
            {
                if (check(i, V, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
