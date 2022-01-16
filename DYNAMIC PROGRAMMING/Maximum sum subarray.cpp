/*
   Problem:- Given an array, find the maximum sum subarray in that
   array. The elememts can be positive or negative.
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MAXN = 1e5 + 7;
int dp[MAXN];

// states :- dp(i) = maximum sum subarray ending at index 'i'
// transition :- dp(i) = v[i] + max(0,dp(i-1))
// answer :- maximum of all dp[i] where 0<=i<=(n-1)
// time complexity :- O(N)
// auxiliary space :- O(N)

int max_sum(vector<int> &v, int i)
{
    if(i == -1) return 0;

    if(dp[i] != -1) return dp[i];

    int temp = 0;

    temp = v[i] + max(0, max_sum(v, i - 1));

    return (dp[i] = temp);
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n;
    cin >> n;

    vector<int> v(n);

    for(auto i = 0; i < n; ++ i)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans = max_sum(v, n - 1);

    for(auto i = 0; i < n; ++ i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}
