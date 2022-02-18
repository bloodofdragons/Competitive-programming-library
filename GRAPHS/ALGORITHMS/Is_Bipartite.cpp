// reinitialize for every testcase
bool is_bipart = true;
vector<int> visited;

void dfs(int node, int colour)
{
    visited[node] = colour;

    for (auto && i : g[node])
    {
        if (not visited[i])
        {
            dfs(i, 3 - colour);
        }
        else
        {
            if (visited[node] == visited[i])
            {
                is_bipart = false;
            }
        }
    }
}
