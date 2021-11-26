/**
    Author :- Rajat Shahi
    It's never too late !!
**/

#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Max_Queue
{
    deque<T> dq;

    T get_max()
    {
        return dq.front();
    }

    void push(T x)
    {
        while(not dq.empty() and dq.back() < x)
        {
            dq.pop_back();
        }

        dq.push_back(x);

        return ;
    }

    void pop(T x)
    {
        if(not dq.empty() and dq.front() == x)
        {
            dq.pop_front();
        }

        return ;
    }

};


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    max_queue<int> q;

    q.push(10);
    q.push(-1);
    q.push(100);

    cout<<q.get_max()<<endl;

}
