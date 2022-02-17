
string to_string(string s)
{
    return '"' + s + '"';
}
string to_string(const char *s)
{
    return to_string((string) s);
}
string to_string(bool b)
{
    return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out()
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

template<typename T>
void debug_out(queue<T> q)
{
    cerr << "{ ";
    while(not q.empty())
    {
        cerr << q.front() << " , ";
        q.pop();
    }
    cerr << "}";
}

template<typename T>
void debug_out(stack<T> st)
{
    cerr << "{ ";
    while(not st.empty())
    {
        cerr << st.top() << " , ";
        st.pop();
    }
    cerr << "}";
}

template<typename T>
void debug_out(priority_queue<T> pq)
{
    cerr << "{ ";
    while(not pq.empty())
    {
        cerr << pq.front() << " , ";
        pq.pop();
    }
    cerr << "}";
}

void debug_out(string str)
{
    cerr << str << endl;
}


#ifndef ONLINE_JUDGE
#define debug(...) cerr << "Line " << __LINE__ << ": "<< "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif