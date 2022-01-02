#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define endl "\n"

using Board = vector<vector<int>>;  // representing the board as 2 dimensional array


// Solve the problem recursively and store the answer found in 'res'
void SudokuSolver(Board &sudoku, vector<Board> &res)
{
    // Let's first check whether there is any empty cell or not.
    // If there exists no empty cell then there are no solutions
    int emptyi = -1, emptyj = -1;

    for(int i = 0; i < 9 and emptyi == -1; i++)
    {
        for(int j = 0; j < 9 and emptyj == -1; j++)
        {
            if(sudoku[i][j] == -1)  // this cell is empty
            {
                emptyi = i;
                emptyj = j;
                break;
            }
        }
    }

    // BASE CASE :- If there are no empty cells then return the answer
    // If any call reaches to the base case then it means the current state of the board is our answer

    if(emptyi == -1 or emptyj == -1)
    {
        res.push_back(sudoku);
        return;
    }

    // Now, there is an empty cell and we have to find the number which we will put in this cell.

    vector<bool> Can_Use(10, true); // This vector will tell us whether we can use any number from 0-9 or not

    // If the value of Can_Use[i] = false, It means 'i' is already used where 'i' can be any value from 0 to 9


    /*
        For checking whether we can use a particular number or not we have to check the following conditions :-
        1- The number doesn't exist in the same row.
        2- The number doesn't exist in the same column.
        3- The number doesn't exist in the small square in which we are filling the number.
    */

    // So, now we will go to these conditions and mark which numbers are already used in these conditions.

    for(int i = 0; i < 9; i++)
    {
        // Check which numbers are used in the same row.
        if(sudoku[emptyi][i] != -1)
        {
            Can_Use[sudoku[emptyi][i]] = false; // sudoku[emptyi][i] is already used.
        }

        // Check which numbers are used in the same column.
        if(sudoku[i][emptyj] != -1)
        {
            Can_Use[sudoku[i][emptyj]] = false; // sudoku[i][emptyj] is already used.
        }
    }
    // Now, we have to check that small 9*9 square in which we are currently filling the values.
    // To do that, first find the centre of that square and check for that square

    // centre of the same block
    int centrei = (emptyi / 3) * 3 + 1;
    int centrej = (emptyj / 3) * 3 + 1;

    // so don't have to use the same number twice in a block

    for(int curri = centrei - 1; curri <= (centrei + 1); curri++)
    {
        for(int currj = centrej - 1; (currj <= centrej + 1); currj++)
        {
            if(sudoku[curri][currj] != -1)
            {
                Can_Use[sudoku[curri][currj]] = false; // this number is used in the same block
            }
        }
    }
    // now recursively fill the next empty spaces

    for(int val = 1; val <= 9; val++)
    {
        if(Can_Use[val] == false) continue;

        sudoku[emptyi][emptyj] = val; // Fill the empty cell with value 'val'
        SudokuSolver(sudoku, res);
    }

    // We have checked the current state by filling the empty space with value 'val'.
    // Now we have make the board to it's original state by assigning the intial value

    // This process is known as the backtracking
    sudoku[emptyi][emptyj] = -1;
}



int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    Board sudoku(9, vector<int>(9, -1)); // -1 in any cell means the cell is empty

    // taking the input of the board
    for(int i = 0; i < 9; i++)
    {
        string line;
        cin >> line;

        for(int j = 0; j < 9; j++)
        {
            // If the current cell is given empty
            if(line[j] == '*')
            {
                continue;
            }

            // line[j] is of the type 'char' having value '0'-'9'
            // So, we have to convert it into integer
            int num = line[j] - '0';
            sudoku[i][j] = num;
        }
    }

    // we will store the answer as a complete board and there might be more than
    // one possible answer so we will try to store all of them.

    vector<Board> res;  // store the possible solutions for the given sudoku
    SudokuSolver(sudoku, res);  // call the recursive funtion which will give us the possible solutions

    if(res.size() == 0)
    {
        cout << "No solutions" << endl;
    }
    else if(res.size() > 1)
    {
        cout << "There exists more than one solution" << endl;
    }
    else
    {
        cout << "There exist only one solution" << endl;
    }

    // now we will print the solution if it exists

    if(res.size() >= 1)
    {
        Board ans = res[0]; // we will get the one possible solution and print it.

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << ans[i][j] << " ";
            }

            cout << endl;
        }
    }

}
