
// problem :- Given an array. find the length of longest increasing subsequence (LIS)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> dp((int)1e5, -1);
vector<int> v;
int n;


// states :- DP(i) = length of LIS ending at index 'i'
// transitions :- DP(i) = max(1,1+DP(j)) where value of j is in the range [0,i-1]

// time complexity :- O(n^2)

int LIS(int i)
{
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int temp = 1;

    for(int j = 0; j < i; j++)
    {
        if(v[i - 1] > v[j - 1])
        {
            temp = max(temp, 1 + LIS(j));
        }
    }

    return (dp[i] = temp);
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> n;
    v.resize(n);

    for(auto i = 0; i < n; ++ i)
    {
        cin >> v[i];
    }

    int ans = 0;

    ans = LIS(n);

    for(auto i = 0; i <= n; ++ i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}