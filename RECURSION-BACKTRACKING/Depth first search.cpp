#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;  // Graph data structure

// Search for node 'v' and then recursively search for all nodes
// which can be reached in one step from 'v'
void dfs(int v, const Graph &G, vector<bool> &seen)
{
    seen[v] = true;

    for(auto next : G[v])
    {
        if(seen[next]) continue; // Do not search if you have already visited
        dfs(next, G, seen);
    }
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int N, M;   // number of vertices and edges
    cin >> N >> M;

    Graph G(N); // graph with 'N' vertices

    for(int i = 0; i < M; i++)
    {
        int s, d;
        cin >> s >> d; // extend a directed edge from node 's' to 'd'
        G[s].push_back(d);
    }

    vector<bool> seen(N, false); // initially all nodes are 'not visited'

    // Search recursively
    // Graph can be disconnected too. So, this step is important.
    for(int v = 0; v < N; v++)
    {
        if(seen[v]) continue; // do not search if you have already visited
        dfs(v, G, seen);
    }
}
