#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int recur(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
{
    if(i == -1 or j == -1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = max(recur(str1, str2, i - 1, j, dp), recur(str1, str2, i, j - 1, dp));

    if(str1[i] == str2[j])
    {
        dp[i][j] = max(dp[i][j], 1 + recur(str1, str2, i - 1, j - 1, dp));
    }

    return dp[i][j];
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n, m;
    cin >> n >> m;
    string str1, str2;
    cin >> str1 >> str2;

    // we have to find the LCS of these two strings.

    // dp state :- dp(i,j) = LCS of str1(0---i) and str2(o---j)

    // transitions :- dp(i,j) = max(dp(i-1,j),dp(i,j-1)) if str1[i]!=str2[j]
    //                dp(i,j) = max(dp[i-1][j],dp(i,j-1), 1+ dp(i-1,j-1)) if str1[i]==str2[j]

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = recur(str1, str2, n - 1, m - 1, dp);

    // we can directly output the answer but for safer side
    // i will think that maybe the LCS of str1 and str2 can be the LCS of
    // str1[0----i] and str2[0----j] for any possible values of 'i' and 'j'

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
