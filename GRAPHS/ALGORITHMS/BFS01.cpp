vector<pair<int, int>> g[100100];   // weigted graph
int dist[100100];   // distance array
int n, m;   // n = no. of nodes , m = no. of edges

// 0-1 BFS -> We give a source and it fills the distance array
void BFS01(int src)
{
    deque<int> dq;

    for(int i = 1; i <= n; i++)
    {
        dist[i] = 1001001001;
    }

    dist[src] = 0;
    dq.push_back(src);

    while(not dq.empty())
    {
        int curr = dq.front();
        dq.pop_front();

        for(auto &&v : g[curr])
        {
            int neigh = v.first;
            int weight = v.second;

            if(dist[neigh] > dist[curr] + weight)
            {
                dist[neigh] = dist[curr] + weight;

                if(weight == 0)
                {
                    dq.push_front(neigh); 
                }
                else
                {
                    dq.push_back(neigh);
                }
            }
        }
    }
}
