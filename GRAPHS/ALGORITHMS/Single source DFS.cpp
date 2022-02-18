vector<int> visited;

// visited store the comp number of each node
void dfs(int node, int curr_comp)
{
    visited[node] = curr_comp;

    for (auto && i : g[node])
    {
        if (not visited[i])
        {
            dfs(i, curr_comp);
        }
    }
}

// n = total number of nodes
void DFS(int n)
{
    visited.resize(n + 1); // graph is 1-index based
    int comp_cnt = 0;  // total number of connected component
    int curr_comp = 1; // current component number

    for (int i = 1; i <= n; i++)
    {
        if (not visited[i])
        {
            dfs(i, curr_comp);
            comp_cnt++;
        }
    }
}
