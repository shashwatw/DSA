#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    // Graph here is stored as a Matrix

    int adj[n + 1][m + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}

// Path: Graphs/adjacency-list.cpp

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Graph here is stored as a Adjacency List

    vector<int> adj[n + 1];

    // SC = O(E)

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // u---->v
        adj[u].push_back(v);
    }

    return 0;
}