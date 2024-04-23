#include <iostream>
#include <fstream>
#include <limits.h>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent)
{
    int V = rGraph.size() - 1; 
    vector<bool> visited(V + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= V; v++) 
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t)
{
    int V = graph.size() - 1; 
    vector<vector<int>> rGraph(V + 1, vector<int>(V + 1));
    for (int u = 1; u <= V; u++) // Adjusted for 1-based indexing
        for (int v = 1; v <= V; v++) // Adjusted for 1-based indexing
            rGraph[u][v] = graph[u][v];

    vector<int> parent(V + 1);

    int max_flow = 0; 
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");

    int V;
    cin >> V; 

    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));

    int s, t;
    cin >> s >> t; 
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        graph[u][v] = w;
    }

    cout <<fordFulkerson(graph, s, t);

    return 0;
}
