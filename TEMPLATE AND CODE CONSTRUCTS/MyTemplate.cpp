/***

 *  Author:- Rajat Shahi (Blood_Of_Dragons)
 *  It's just the beginning .... Wait !!!  Have patience !!!

***/

#include<bits/stdc++.h>
using namespace std;


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set =
//     tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


using ll = long long ;
using ull = unsigned long long;
using lld = long double;


// pairs
using pii = pair<int, int>;
using pll = pair<long long, long long>;


// vectors
using vi = vector<int>;
using vll = vector<long long>;
using vbool = vector<bool>;
using vstring = vector<string>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;


// pairs,map,set
#define ff  first
#define ss  second
#define ump unordered_map
#define ust unordered_set


// vectors
#define   pb      push_back
#define   eb      emplace_back
#define   pf      push_front
#define   popf    pop_front
#define   popb    pop_back
#define   ub      upper_bound
#define   lb      lower_bound

#define   sz(v)   ((int)(v).size())
#define   all(v)  v.begin(),v.end()
#define   rall(v) v.rbegin(),v.rend()


// Loops --> take care of the reverse ones
#define rep(i,a,n)              for(int i = a ; i< n ; i++)
#define per(i,n,a)              for(int i = n-1 ; i >= a ; i--)
#define repe(i,a,n)             for(int i = a ; i <= n ; i++)
#define pere(i,n,a)             for(int i = n ; i >= a ; i--)
#define foreach(i,container)    for(auto&& i:container)


#define   endl      "\n"
#define testcases   int t;cin>>t;while(t--)


const long long INF = 1001001001001001001ll;
const int inf = 1001001001;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const lld PI =  acos( (lld) - 1);


// direction vectors
int DX8[] = {1, -1, 0, 0, -1, 1, -1, 1}; // for eight directions
int DY8[] = {0, 0, 1, -1, 1, 1, -1, -1}; // for eight directions
int DX4[] = {1, -1, 0, 0}; // for 4 directions
int DY4[] = {0, 0, 1, -1}; // for 4 directions



//----------------------------DEBUGGING GOES HERE---------------------------//


#define debug(var)  do{std::cerr << #var << " : ";view(var);}while(0)
template<typename T> void view(T e)
{
    std::cerr << e << endl;
}
template<typename T, typename K> void view(pair<T, K> e)
{
    std::cerr << "(" << e.first << ", " << e.second << ")" << endl;
}
template<typename T> void view(const set<T> &st)
{
    for(const auto &e : st)
    {
        std::cerr << e << " ";
    }
    std::cerr << endl;
}
template<typename T, typename K> void view(const map<T, K> &mp)
{
    for(const auto &k : mp)
    {
        std::cerr << "(" << k.first << ", " << k.second << ")" << endl;
    }
}
template<typename T> void view(const std::vector<T> &v)
{
    for(const auto &e : v)
    {
        std::cerr << e << " ";
    }
    std::cerr << endl;
}
template<typename T> void view(const std::vector<std::vector<T> > &vv)
{
    cerr << endl;
    int cnt = 0;
    for(const auto &v : vv)
    {
        cerr << cnt << "th : ";
        view(v);
        cnt++;
    }
    cerr << endl;
}


//----------------------READING VECTORS AND PAIRS-------------------------//

// taking input in the array
template<class T>
void readarray(T &arr)
{
    foreach(i, arr) cin >> i;
}

template<class T>
void writearray(T &arr)
{
    foreach(i, arr) cout << i << " ";
}

template<class T>
T myceil(T x, T y)
{
    return (x % y == 0) ? (x / y) : ((x / y) + 1);
}

//reading a vector of pairs
template<class T>
void readpairs(T &arr)
{
    foreach(i, arr) cin >> i.first >> i.second;
}

//-------------------------MATHEMATICAL ALGORITHMS--------------------------//

ll power(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a;} a = a * a; p >>= 1;} return ret;}
ll modpow(ll a, ll p, ll mod){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}


//--------------------------------------------------------------------------//


int main()
{
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(ios::badbit | ios::failbit);

        // #ifndef ONLINE_JUDGE
            // freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        // #endif

        





        return 0;
}
