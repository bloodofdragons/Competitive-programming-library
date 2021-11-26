/**
    Author :- Rajat Shahi
    It's never too late !!
**/

#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Min_Queue
{
    deque<T> dq;

    void push(T x)
    {
        while(not dq.empty() and dq.back() > x)
        {
            dq.pop_back();
        }

        dq.push_back(x);
        return;
    }

    void pop(T x)
    {
        if(not dq.empty() and dq.front() == x)
        {
            dq.pop_front();
        }

        return ;
    }

    T get_min()
    {
        return dq.front();
    }
};



int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    Min_Queue<int> q;

    q.push(10);
    q.push(-20);
    q.push(111);
    q.push(-119);

    // -119 111
    cout << q.get_min() << endl;
    q.pop(-119);
    cout << q.get_min() << endl;
}
