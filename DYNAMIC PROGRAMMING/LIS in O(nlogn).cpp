// problem :- Given an array. find the length of longest increasing subsequence (LIS)

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// This solution for finding the LIS takes O(nlogn) time.

int LIS(vector<int> &v, int n)
{
    vector<int> ans;

    for(auto i = 0; i < n; ++ i)
    {
        if(ans.empty() or v[i] > ans.back())
        {
            ans.push_back(v[i]);
        }
        else
        {
            auto it = lower_bound(ans.begin(), ans.end(), v[i]);
            *it = v[i];
        }
    }

    return (ans.size());
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

    int ans = 0;
    ans = LIS(v, n);
    cout << ans << endl;
}
