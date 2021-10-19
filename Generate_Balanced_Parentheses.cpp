#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

vector<string> generate_balanced_strings(int n)
{
    vector<string> complete_sequence;

    if(n == 0)
    {
        complete_sequence.push_back("");
        return complete_sequence;
    }

    for(int i = 0; i <= n - 1; i++)
    {
        vector<string> inside_bracket = generate_balanced_strings(i);
        vector<string> outside_bracket = generate_balanced_strings(n - 1 - i);

        for(string a : inside_bracket)
        {
            for(string b : outside_bracket)
            {
                string concatenated_string = '(' + a + ')' + b;
                complete_sequence.push_back(concatenated_string);
            }
        }

    }

    return complete_sequence;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> ans = generate_balanced_strings(n);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
