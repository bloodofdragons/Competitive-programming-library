#include<bits/stdc++.h>
using namespace std;

bool Is_Balanced(string str)
{
    int open = 0, close = 0;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            open++;
        }
        else if(str[i] == ')')
        {
            close++;
        }
        else
        {
            return false;
        }

        if(close > open) return false;
    }

    return (open == close);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    bool ans = Is_Balanced(str);

    if(ans)
    {
        cout << "BALANCED" << endl;
    }
    else
    {
        cout << "NOT BALANCED" << endl;
    }

}
