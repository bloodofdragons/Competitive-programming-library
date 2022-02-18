void dfs(int node, int comp)
{
    visited[src] = comp;

    for (auto && i : g[node])
    {
        if (not visited[i])
        {
            dfs(i, comp);
        }
    }
}
