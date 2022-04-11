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

vector<bool> vis;
vector<int> intime, outtime;


void dfs(vector<vector<int>>& g, int &ptr, int src)
{
	intime[src] = ptr++;
	vis[src] = true;

	for (auto && i : g[src])
	{
		if (not vis[i])
		{
			dfs(g, ptr, i);
		}
	}

	outtime[src] = ptr++;
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	vis.resize(n, false);
	intime.resize(n);
	outtime.resize(n);

	for (auto i = 0; i < m; i++)
	{
		int s, d;
		cin >> s >> d;
		g[s].push_back(d);
		g[d].push_back(s);
	}

	int ptr = 0;
	dfs(g, ptr, 0);

	for (int i = 0; i < n; i++)
	{
		cout << i << " : " << intime[i] << " , " << outtime[i] << endl;
	}

}
