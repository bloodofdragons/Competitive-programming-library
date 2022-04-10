// Author : RAJAT SHAHI (@blood_of_dragons)
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include"/Users/rajat.shahi/Desktop/CPP/debug.h"
#endif
#ifdef ONLINE_JUDGE
#define debug(...) 42
#endif

#define endl '\n'	//remove for interactive problems 
const int mod = 1e9 + 7;	// 998244353;
#define rep(i,a,b) for(auto i=a;i<=b;i++)
#define per(i,a,b) for(auto i=a;i>=b;i--)
using ll = long long;
using vll = vector<long long>;
const int MAXN = 2e5 + 5;
const int inf = 1001001001;
const long long INF = 1001001001001001001ll;

int n, m;
vector<vector<int>> g;
vector<int> going_order;
vector<int> return_order;
vector<int> vis;

void dfs(int src, int &first_ptr, int &last_ptr)
{
	vis[src] = true;
	going_order[src] = first_ptr++;

	for (auto && i : g[src])
	{
		if (vis[i] == false)
		{
			dfs(i, first_ptr, last_ptr);
		}
	}

	return_order[src] = last_ptr++;
}



int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);

	cin >> n >> m;

	g.clear();
	g.resize(n);	// 0 indexed graph
	going_order.resize(n);
	return_order.resize(n);
	vis.resize(n, false);

	for (auto i = 0; i < m; i++)
	{
		int s, d;
		cin >> s >> d;

		g[s].push_back(d);
		g[d].push_back(s);
	}

	int first_ptr = 0, last_ptr = 0;
	dfs(0, first_ptr, last_ptr);

	for (auto i = 0; i < n; i++)
	{
		cout << "node " << i << " :  " << going_order[i] << " " << return_order[i] << endl;
	}

}
