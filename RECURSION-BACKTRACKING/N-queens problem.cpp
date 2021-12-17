/**
    Author :- Rajat Shahi
    It's never too late !!
**/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int ans;    // It will store the number of arrangements possible for the given size of the baord.

vector<int> queens_placed; // It will store the column number where queens are placed for each row.


void Print_Board(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(queens_placed[i] == j)
            {
                cout << "Q";
            }
            else
            {
                cout << "*";
            }
        }

        cout << endl;
    }

    cout << endl;
}


void recur(int curr_row, int n)
{
    // BASE CASE --> If current row equal to the size of the board then return.
    if(curr_row == n)
    {
        ans++;
        Print_Board(n);
        return;
    }

    for(int curr_col = 0; curr_col < n; curr_col++)
    {
        bool Is_Pos = true;

        for(int prev_row = 0; prev_row < curr_row; prev_row++)
        {
            int prev_col = queens_placed[prev_row];

            /*
                    We will check the following conditions:-

                    1- There is no queen placed in the same column of the previous row.
                    2- There is no queen placed in both the diagonals.
            */

            if(prev_col == curr_col or (abs(prev_row - curr_row) == abs(prev_col - curr_col)))
            {
                Is_Pos = false;
            }

            // If for any row the move is not possible then stop checking
            if(Is_Pos == false)
            {
                break;
            }
        }

        // If the move is possible then do the move else it will backtrack
        if(Is_Pos == true)
        {
            queens_placed.push_back(curr_col);  // do the move
            recur(curr_row + 1, n);     // move to the next choices
            queens_placed.pop_back();   // remove the move (return to the previous state of the board)
        }

    }

}

void Nqueens(int n)
{
    recur(0, n);    // recursively start putting the queens from 0th row and then moving on to the next row.
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n;      // Size of the board
    cin >> n;
    Nqueens(n);
    cout << ans << endl;
}
