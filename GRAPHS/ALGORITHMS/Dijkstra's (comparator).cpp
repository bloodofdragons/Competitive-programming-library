
// custom comparator for heap (priority-queue)
// for heaps we don't create functions rather we create class
class prioritize
{
public:
    bool operator ()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

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

    // {node,distance}
    priority_queue<pair<int, int>, vector<pair<int, int>>, prioritize> pq;

    pq.push(make_pair(src, 0));

    while(not pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();

        if(vis[curr.first])
        {
            continue; // we have set distance (already visited)
        }

        vis[curr.first] = 1;

        // relax all the nodes which can be reached
        for(auto &&v : g[curr.first])
        {
            int neigh = v.first;
            int weigh = v.second;

            // relaxation of nodes
            if(dist[neigh] > dist[curr.first] + weigh)
            {
                dist[neigh] = dist[curr.first] + weigh;
                pq.push(make_pair(neigh, dist[neigh]));
            }
        }
    }
}
