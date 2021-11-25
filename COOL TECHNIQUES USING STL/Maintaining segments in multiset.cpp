/**
    Author :- Rajat Shahi
    It's never too late !!
**/



/*

Problem :- You are given 'Q' queries and there are two types of queries.
           If you get '+' as a query you have to insert a segment having
           end points as 'l' and 'r'. If you get query of 2nd type then
           you have to output the number of segments which do not overlap
           with each other.

           This problem can also be asked as how many disjoint shadows are
           on the number line if we project light on segments from the vertical
           direction.

*/


#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const long long mod = 1e9 + 7;

multiset<pair<long long, long long>> mt;

void insert(long long l, long long r)
{
    /*  we will not insert at every case and delete some segment
        Instead there is a better option that we change the values of
        'L' and 'R' and delete the overlapping segments and insert the
        'L' and 'R' at the last :)
    */

    auto it = mt.lower_bound({l, -mod * mod});

    if(it != mt.begin())
    {
        it--;

        if(it->second >= r) return;

        if(it->second >= l)
        {
            l = min(it->first, l);
            r = max(it->second, r);

            mt.erase(it);
        }
    }

    // Now we have to work on the case in which we have to find the segment
    // which starts before 'R' but ends after it.


    it = mt.upper_bound({r, mod * mod});

    if(it != mt.begin())
    {
        it--;

        if(it->second >= r)
        {
            l = min(it->first, l);
            r = max(it->second, r);
            mt.erase(it);
        }
    }

    // now there maybe be various segments which are completely subsumed
    // in the largest segment. So, we have to delete those extra segments.
    // Let's delete them one by one.

    // If you are getting TLE then,this might be the reason for TLE
    while(true)
    {
        it = mt.lower_bound({l, -mod * mod});

        if(it != mt.end())
        {
            if(it->first > r)
            {
                break;
            }

            mt.erase(it);
        }
        else
        {
            break;  // don't forget this case otherwise TLE :)
        }
    }

    mt.insert({l, r});
}

int get_ans()
{
    return mt.size();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        char ch;
        cin >> ch;

        if(ch == '+')
        {
            long long l, r;
            cin >> l >> r;
            insert(l, r);
        }
        else
        {
            cout << get_ans() << endl;
        }
    }
}
