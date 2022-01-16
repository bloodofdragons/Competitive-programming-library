// Problem :- Given two arrays 'A' and 'B' and all the elements in array 'A'
// are distinct. Find the Longest common subsequence of the arrays.


// If all the elements in the array are distinct we can find the
// LCS using LIS by replacing the elements from [1,n] in array 'A'
// and doing the same changes in array 'B'

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int LIS(vector<int> &v)
{
    vector<int> ans;

    for(int i = 0; i < (int)v.size(); i++)
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

    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);

    for(auto i = 0; i < n; ++ i)
    {
        cin >> A[i];
    }

    for(auto i = 0; i < m; ++ i)
    {
        cin >> B[i];
    }

    map<int, int> mp;

    for(auto i = 0; i < n; ++ i)
    {
        mp.insert({A[i], i + 1});
    }

    vector<int> temp;

    for(auto i = 0; i < m; ++ i)
    {

        if(mp.find(B[i]) != mp.end())
        {
            temp.push_back(mp[B[i]]);
        }
    }

    int ans = LIS(temp);

    cout << ans << endl;
}
