// initialize for each test case
vector<int> dist;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (not q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (auto && v : g[curr])
        {
            if (dist[v] > 1 + dist[curr])
            {
                q.push(v);
                dist[v] = 1 + dist[curr];
            }
        }
    }
}
