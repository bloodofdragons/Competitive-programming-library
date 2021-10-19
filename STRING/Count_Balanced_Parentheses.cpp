#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int mod = 1e9 + 7;

long long ans[MAXN];

// The total number of brackets are (2*n) --> 'n' opening and 'n' closing
void compute_balanced()
{
    ans[0] = 1;

    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 0; j <= (i - 1); j++)
        {
            ans[i] = (ans[i] + (ans[i - 1 - j] * ans[j]) % mod) % mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    compute_balanced();

    cout << ans[4] << endl;
}
