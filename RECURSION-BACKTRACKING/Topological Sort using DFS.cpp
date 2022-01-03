#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>> ; // graph

// topological sort
void Topological_Sort(int v, const Graph &G, vector<bool> &seen, vector<int> &order)
{
    seen[v] = true;

    for(auto next : G[v])
    {
        if(seen[next]) continue; // do not search if it is already visited
        Topological_Sort(next, G, seen, order);
    }

    order.push_back(v); // push the current vertex in the vector
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
        int s, d;   // extend a directed edge from 's' to 'd'
        cin >> s >> d;

        G[s].push_back(d);
    }


    vector<bool> seen(N); // in the intial state all nodes are "not visited"
    vector<int> order;  // stores the topological sort order

    // topological sort
    for(int v = 0; v < N; v++)
    {
        if(seen[v]) continue;   // do not visit the vertex if it is already visited
        Topological_Sort(v, G, seen, order);
    }

    reverse(order.begin(), order.end());   // reverse the vector to get the topological sort

    // Output the topological sort order for the given graph
    for(auto v : order) cout << v << " ";
    cout << endl;
}
