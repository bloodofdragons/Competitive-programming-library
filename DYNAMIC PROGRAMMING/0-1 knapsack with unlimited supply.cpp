// problem :- knapsack problem with unlimited supply

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int N, W;
vector<int> profit;
vector<int> weight;
vector<vector<int>> dp(5001, vector<int>(5001, -1));

// states :- dp(i,w) --> maximum profit we can get by choosing some items from first 'i' items 
// with total weight 'w'

// transition :- dp(i,w) = dp(i-1,w) + dp(i,w-wt[i]) + pft[i]

// time complexity :- O(N*W)
// space complexity :- O(N*W)

int knapsack(int i, int w)
{
    if(i == 0) return 0; // all elements are finished
    else if(w == 0) return 0; // the given limit of bag is 0

    if(dp[i][w] != -1) return dp[i][w];

    dp[i][w] = knapsack(i - 1, w);

    if(w >= weight[i - 1]) // the bag has capacity to have this item
    {
        dp[i][w] = max(dp[i][w], knapsack(i , w - weight[i - 1]) + profit[i - 1]);
    }

    return dp[i][w];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> N >> W;

    profit.resize(N);
    weight.resize(N);

    for(auto i = 0; i < N; ++ i)
    {
        cin >> weight[i] >> profit[i];
    }

    int ans = knapsack(N, W);

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
