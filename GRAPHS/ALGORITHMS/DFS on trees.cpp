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

int n;
vector<vector<int>> g;

// src = current node which is to be searched
// par = parent of the current node (-1 if curr node is root node)

void dfs(int src, int par)
{
	for (auto && nsrc : g[src])
	{
		if (nsrc == par) continue;
		dfs(nsrc, src);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);

	cin >> n;

	g.resize(n);

	for (auto i = 0; i < n - 1; i++)
	{
		int s, d;
		cin >> s >> d;
		s--; d--;
		g[s].push_back(d);
		g[d].push_back(s);
	}

	int root = 0;

	dfs(root, -1);	// parent of the root node is -1
}
