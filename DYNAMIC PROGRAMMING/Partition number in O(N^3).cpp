/*
    PROBLEM :- Given  a number 'N' . find the number of ways you can
    write 'N' as a sum of natural numbers. (don't consider
    permutations.)  [ commonly known as partition number ]
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
DP STATES --> dp(i,taken) = we have to create i and the last number we took was "taken"
              So, we can take numbers from [taken,i]

TRANSITION --> for all j where j = [taken,i] ,  dp(i,taken) = dp(i-j,j);

BASE CASES (WE ALREADY KNOW ANSWERS FOR THESE) --> 1- if number<=0 then # of ways = 0
                                                   2- taken > i then it is impossible to make 'i'

Time complexity --> # states * (average number of transitions across all states)
                --> O(n^2)*O(n) = O(n^3)
*/

int dp[1001][1001];

int partion_number(int i, int taken)
{
    // if you will change this sequence of base case then answer might be incorrect.
    // WHY ?? --> if(i<taken) statement is executed first then it will return 0 doesn't matter whether
    // the value of 'i' is 0 or not because at that instant i<taken is correct.
    if(i == 0) return 1;
    else if(i < taken) return 0;
    else if(i < 0) return 0;

    if(dp[i][taken] != -1) return dp[i][taken]; // this subproblem is already calculated. so return answer directly.

    int curr_ans = 0 ;

    for(int j = taken; j <= i; j++)
    {
        curr_ans += partion_number(i - j, j);
    }

    return (dp[i][taken] = curr_ans);
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int ans = partion_number(n, 1); // we have to create 'n' and we can take numbers from [1,n]
    cout << ans << endl;
}
