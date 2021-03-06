#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        // Note: in leetcode's examples, they said the top-left square is (0,0), but I arbitrarily chose it to be the bottom right. It changes nothing
        vector<int> boards(2,0); // {player_a_board, player_b_board}. Let the bottom right square of the board be (0,0), going left, then up
        
        // Setting up the winning lines. Binary literals: {100100100,010010010,001001001,111000000,000111000,000000111,100010001,001010100}
        // But, there are no binary literals in c++, so we must convert on our own.
        vector<int> cols_rows_diags{292,146,73,448,56,7,273,84};

        for (int i = 0; i < moves.size(); ++i) {

            const int& row = moves[i][0];
            const int& col = moves[i][1];

            // apply the move.
            boards[i%2] += (1 << (row*3 + col));

            // check for a winner if at least 5 moves happened
            if (i >= 4) {
                for (const int& winning_line : cols_rows_diags) {

                    // this checks if the board contains any of the winning lines
                    // MISTAKE: Originally I had just `(boards[i%2] & winning_line == winning_line)`, but due to weird
                    // order of operations, it evaluated the `==` first, then the bitwise-and. :(. This caused lots of grief
                    if ((boards[i%2] & winning_line) == winning_line) { 
                        return (i%2 == 0) ? "A": "B";
                    }
                }
            }
        }

        // Deal with draws and unfinished games
        return (moves.size() == 9) ? "Draw": "Pending";
    }
};

//V2 (perhaps even faster but slightly worse memory) copied from https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/discuss/441422/JavaPythonC%2B%2B-0ms-short-and-simple-all-8-ways-to-win-in-one-array
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> A(8,0), B(8,0); // 3 rows, 3 cols, 2 diagonals
        for(int i=0; i<moves.size(); i++) {
            int r=moves[i][0], c=moves[i][1];
            vector<int>& player = (i%2==0)?A:B;
            player[r]++;
            player[c+3]++; 
            if(r==c) player[6]++;
            if(r==2-c) player[7]++;
        }
        for(int i=0; i<8; i++) {
            if(A[i]==3) return "A";
            if(B[i]==3) return "B";
        }
        return moves.size()==9 ? "Draw":"Pending";
    }
};