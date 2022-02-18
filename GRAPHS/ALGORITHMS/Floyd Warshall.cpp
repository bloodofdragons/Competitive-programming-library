#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dist(404, vector<long long>(404)); // distance array

// this will fill the distance array
void FloydWarshal(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= n; j++)
        {
            if (i != j) dist[i][j] = 1001001001001001001ll;
        }
    }

    for (k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n, m; // number of nodes and edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;

        dist[s][d] = min(dist[s][d], w);
        dist[d][s] = min(dist[d][s], w);
    }

    FloydWarshal(n);  // give number of nodes as argument
}
