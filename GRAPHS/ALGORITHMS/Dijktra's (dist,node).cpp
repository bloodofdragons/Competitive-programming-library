int n, m;
vector<pair<int, int>> g[100100];   // weighted graph

long long dist[100100]; // distance array
int vis[100100];    // visited array


void dijkstra(int src)
{
    // reset things before dijkstra
    for(int i = 1; i <= n; i++)
    {
        dist[i] = 1001001001001001001ll; // infinity
        vis[i] = 0; // unvisited
    }

    dist[src] = 0;

    // {distance,node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));

    while(not pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();

        if(vis[curr.second])
        {
            continue; // we have set distance (already visited)
        }

        vis[curr.second] = 1;

        // relax all the nodes which can be reached
        for(auto &&v : g[curr.second])
        {
            int neigh = v.first;
            int weigh = v.second;

            // relaxation of nodes
            if(dist[neigh] > dist[curr.second] + weigh)
            {
                dist[neigh] = dist[curr.second] + weigh;
                pq.push(make_pair(dist[neigh], neigh));
            }
        }
    }
}
