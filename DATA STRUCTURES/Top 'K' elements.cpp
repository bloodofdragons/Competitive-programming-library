/**
    Author :- Rajat Shahi
    It's never too late !!
**/

#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyDataStructure
{
private:
    multiset<T> M1, M2;
    T Sum;
    T K;
public:

    MyDataStructure(T k): K(k), Sum(0) {};

    void insert(T x)
    {
        M1.insert(x);
        Sum += x;

        if((int)M1.size() > K)
        {
            T y = *(M1.begin());
            M1.erase(M1.find(y));
            Sum -= y;
            M2.insert(y);
        }
        return;
    }

    void remove(T x)
    {
        if(M2.find(x) != M2.end())
        {
            M2.erase(M2.find(x));
        }
        else if(M1.find(x) != M1.end())
        {
            Sum -= x;
            M1.erase(M1.find(x));

            if(M2.empty()) return;

            T y = *(M2.begin());
            Sum += y;
            M1.insert(y);
            M2.erase(M2.find(y));
        }
        return;
    }

    T get_sum()
    {
        return Sum;
    }

    void print_top_K()
    {
        for(const T i : M1)
        {
            cout << i << " ";
        }

        cout << endl;
    }
};



int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int Q, K;
    cin >> Q >> K;

    MyDataStructure<int> MyDS(K);

    while(Q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x;
            cin >> x;
            MyDS.insert(x);
        }
        else if(type == 2)
        {
            int x;
            cin >> x;
            MyDS.remove(x);
        }
        else
        {
            char ch;
            cin >> ch;
            cout << MyDS.get_sum() << endl;
        }
    }

}
