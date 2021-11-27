/**
    Author :- Rajat Shahi
    It's never too late !!
**/

#include<bits/stdc++.h>
using namespace std;

template<class T>
struct MyDS
{
    multiset<T> mt;
    T sum = 0;

    void insert(T x)
    {
        mt.insert(x);
        sum += x;
    }

    void remove(T x)
    {
        auto it = mt.find(x);
        if(it != mt.end())
        {
            mt.erase(it);
            sum -= x;
        }
    }

    T get_sum()
    {
        return sum;
    }

    T get_min()
    {
        if(mt.empty()) return -1;
        return *(mt.begin());
    }

    T get_max()
    {
        if(mt.empty()) return -1;
        return *(mt.rbegin());
    }

};


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);


    int q;
    cin >> q;

    MyDS<int> b;

    for(auto i = 0; i < q; ++ i)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x;
            cin >> x;

            b.insert(x);

        }
        else if(type == 2)
        {
            int x;
            cin >> x;
            b.remove(x);
        }
        else if(type == 3)
        {
            char ch;
            cin >> ch;
            cout << b.get_min() << endl;
        }
        else if(type == 4)
        {
            char ch;
            cin >> ch;
            cout << b.get_max() << endl;
        }
        else
        {

            char ch;
            cin >> ch;
            cout << b.get_sum() << endl;
        }
    }
}
