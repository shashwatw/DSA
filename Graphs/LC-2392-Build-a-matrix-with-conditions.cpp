//! https://leetcode.com/problems/build-a-matrix-with-conditions/description/

//& Intuition and Explanation:

//* Building the Graph:
//^ We build a directed graph using adjacency lists based on the given conditions for rows and columns. Each condition indicates a directed edge from one node to another.

//* Topological Sort:
//^ We perform a topological sort on the graph to determine the order of nodes such that all directed edges go from left to right. This helps in arranging the elements in a sequence that respects the given conditions.
//^ We use Kahn's algorithm (BFS-based) for topological sorting, which also helps in detecting cycles. If a cycle is detected (i.e., the topological sort does not include all nodes), we return an empty array.

//* Filling Missing Nodes:
//^ After obtaining the topological order, we fill in any missing nodes to ensure that all nodes from 1 to k are included. This ensures that the matrix will have all nodes properly placed.

//* Building the Matrix:
//^ We map the column indices based on the column topological order.
//^ We then fill the matrix by placing nodes in the correct row and column based on the obtained topological orders.
//^ This approach ensures that the resultant matrix respects the given row and column conditions while handling possible cycles and missing nodes.

class Solution
{
private:
    // Function to build a graph from given conditions
    vector<vector<int>> buildGraph(int k, vector<vector<int>> conditions)
    {
        // Initialize an adjacency list for the graph
        vector<vector<int>> graph(k + 1);

        // Iterate over the conditions and build the directed graph
        for (auto it : conditions)
        {
            int u = it[0], v = it[1];
            graph[u].push_back(v);
        }

        return graph;
    }

    // Function to perform topological sort on the graph
    vector<int> topoOrder(int k, vector<vector<int>> &graph)
    {
        // Vector to keep track of in-degrees of nodes
        vector<int> indeg(k + 1, 0);

        // Calculate in-degrees of all nodes
        for (int node = 1; node <= k; node++)
        {
            for (auto child : graph[node])
            {
                indeg[child]++;
            }
        }

        // Queue to process nodes with zero in-degree
        queue<int> q;
        for (int node = 1; node <= k; node++)
        {
            if (indeg[node] == 0)
            {
                q.push(node);
            }
        }

        vector<int> topoSort; // Resultant topological order

        // Perform BFS to generate topological sort
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            // Decrease in-degree of child nodes and add to queue if in-degree becomes zero
            for (auto child : graph[node])
            {
                indeg[child]--;
                if (indeg[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        // If topological sort does not include all nodes, return an empty vector indicating a cycle
        if (topoSort.size() != k)
        {
            return {};
        }
        return topoSort;
    }

    // Function to fill the topological order array with any missing nodes
    void fillTopoArray(int k, vector<int> &topoArray)
    {
        unordered_set<int> vis(topoArray.begin(), topoArray.end());

        // Add missing nodes to the topological order array
        for (int el = 1; el <= k; el++)
        {
            if (vis.find(el) == vis.end())
            {
                topoArray.push_back(el);
            }
        }
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        // Build graphs for row and column conditions
        vector<vector<int>> rowGr = buildGraph(k, rowConditions);
        vector<vector<int>> colGr = buildGraph(k, colConditions);

        // Get topological order for rows and columns
        vector<int> rowTopo = topoOrder(k, rowGr);
        vector<int> colTopo = topoOrder(k, colGr);

        vector<vector<int>> ans;

        // If either topological order is empty, return an empty matrix indicating an invalid condition
        if (rowTopo.empty() || colTopo.empty())
        {
            return ans;
        }

        // Fill the topological order arrays with any missing nodes
        fillTopoArray(k, rowTopo);
        fillTopoArray(k, colTopo);

        // Map to store the column index of each node
        unordered_map<int, int> colInd;
        for (int j = 0; j < k; j++)
        {
            colInd[colTopo[j]] = j;
        }

        // Initialize the result matrix with zeroes
        ans = vector<vector<int>>(k, vector<int>(k, 0));

        // Fill the matrix based on the row and column topological orders
        for (int i = 0; i < k; i++)
        {
            ans[i][colInd[rowTopo[i]]] = rowTopo[i];
        }

        return ans;
    }
};
