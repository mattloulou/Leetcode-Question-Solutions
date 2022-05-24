//Similar to: SAC '22 Code Challenge 5 Junior P5 - English Summative.cpp

#include <unordered_set>
#include <vector>
#include <deque>
#include <cassert>
#include <iostream>
using namespace std;
class Solution {
public:
    
    void printBoard(const vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                cout << board[row][col] + " ";
            }
            cout << endl;
        }
    }

    //starting_row and starting_column should be within range (both [0,8])
    pair<int,int> nextUnsolvedTile(const vector<vector<char>>& board, int starting_row = 0, int starting_col = 0) {
        for (int row = starting_row; row < 9; ++row) {
            for (int col = (row == starting_row) ? starting_col: 0; col < 9; ++col) {
                if (board[row][col] == '.') return pair<int,int>(row,col);
            }
        }
        return pair<int,int>(-1,-1);
    }

    void fillInKnownTiles(vector<vector<char>>& board, deque<pair<int,int>>& solved_tiles, vector<vector<unordered_set<char>>>& possible_numbers) {
        //we will keep going through our solved tiles list and find which ones are now known
        while (!solved_tiles.empty()) {
            
            //get the tile information
            pair<int,int> tile = solved_tiles.front();
            const int& row = tile.first;
            const int& col = tile.second;
            const char& tile_value = board[row][col]; 
            solved_tiles.pop_front();

            //constants for the 3x3 sub-box
            const int top_left_row = (row/3)*3;
            const int top_left_col = (col/3)*3;

            //use the rule of sudoku to remove possibilities from possible_numbers
            for (int i = 0; i < 9; ++i) {

                //HORIZONTAL
                //make sure it is not the same tile
                if (i != col) {
                    possible_numbers[row][i].erase(tile_value);

                    //if the tile just has 1 possibility left, it is solved.
                    if (possible_numbers[row][i].size() == 1 && board[row][i] == '.') {
                        board[row][i] = *(possible_numbers[row][i].begin()); //set the value to the last remaining possible number.
                        solved_tiles.emplace_back(row,i);
                    }
                }

                //VERTICAL
                //make sure it is not the same tile
                if (i != row) {
                    possible_numbers[i][col].erase(tile_value);

                    //if the tile just has 1 possibility left, it is solved.
                    if (possible_numbers[i][col].size() == 1 && board[row][i] == '.') {
                        board[i][col] = *(possible_numbers[i][col].begin()); //set the value to the last remaining possible number.
                        solved_tiles.emplace_back(i,col);
                    }
                }

                //WITHIN 3X3 SUB-BOX
                const int sub_box_row = top_left_row + (i%3);
                const int sub_box_col = top_left_col + (i/3);

                //make sure it is not the same tile
                if (sub_box_row != row && sub_box_col != col) {
                    possible_numbers[sub_box_row][sub_box_col].erase(tile_value);

                    //if the tile just has 1 possibility left, it is solved.
                    if (possible_numbers[sub_box_row][sub_box_col].size() == 1 && board[row][i] == '.') {
                        board[sub_box_row][sub_box_col] = *(possible_numbers[sub_box_row][sub_box_col].begin()); //set the value to the last remaining possible number.
                        solved_tiles.emplace_back(sub_box_row,sub_box_col);
                    }
                }

            }
        }
    }

    //answer_board is the board to be submitted as the solved sudoku board. IDK if this is actually DFS lol because I don't recall what DFS really is...
    void DFSGuesser(bool& finished, vector<vector<char>>& answer_board, vector<vector<char>> current_board, deque<pair<int,int>> solved_tiles, vector<vector<unordered_set<char>>> possible_numbers) {
        if (finished) return;

        //fill in the known tiles that the previous board state guarantees
        fillInKnownTiles(current_board, solved_tiles, possible_numbers);

        //if we have found a solved board, end the program.
        if (nextUnsolvedTile(current_board).first == -1) {
            answer_board = current_board;
            finished = true;
            return;
        } 

        //if the board is not yet solved, used DFS to find the next option
        int unsolved_row = 0; //starting position for the search
        int unsolved_col = 0; //starting position for the search
        while (true) {
            if (finished) return;

            //get info about the next unsolved tile
            pair<int, int> next_tile = nextUnsolvedTile(current_board, unsolved_row, unsolved_col);
            const int& next_row = next_tile.first;
            const int& next_col = next_tile.second;
            if (next_row == -1 || next_row > 9 || next_col > 9) return;

            //if this tile has no possible options, then this board was a failure so we go back a level in DFS
            if (possible_numbers[next_row][next_col].size() == 0) return;

            //loop through all possible values to guess them and recursively call the DFS function.
            for (auto it = possible_numbers[next_row][next_col].begin(); it != possible_numbers[next_row][next_col].end(); ++it) {
                current_board[next_row][next_col] = *it;
                solved_tiles.emplace_back(next_row, next_col);
                DFSGuesser(finished, answer_board, current_board, solved_tiles, possible_numbers);                
                solved_tiles.pop_back();
            }
            current_board[next_row][next_col] = '.';

            //update the next value to search from (1 tile after this one)
            unsolved_col += 1;
            if (unsolved_col >= 9) {
                unsolved_col -= 9;
                unsolved_row += 1;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        //this will be done using topological sort I believe.

        const unordered_set<char> all_numbers = {'1','2','3','4','5','6','7','8','9'};
        vector<vector<unordered_set<char>>> possible_numbers(9, vector<unordered_set<char>>(9, all_numbers));
        deque<pair<int /*row*/, int /*col*/>> solved_tiles;

        //now, we will go through the given board and see which tiles are already given.
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                const char tile_value = board[i][j];
                if (tile_value != '.') {
                    // possible_numbers[i][j].clear();
                    // possible_numbers[i][j].insert(tile_value);
                    solved_tiles.emplace_back(i, j);
                }
            }
        }

        bool board_completed = false;
        DFSGuesser(board_completed, board, board, solved_tiles, possible_numbers);
    }
};

// int main() {
//     vector<vector<char>> test2{vector<char>{'.','.','9','7','4','8','.','.','.'},vector<char>{'7','.','.','.','.','.','.','.','.'},vector<char>{'.','2','.','1','.','9','.','.','.'},vector<char>{'.','.','7','.','.','.','2','4','.'},vector<char>{'.','6','4','.','1','.','5','9','.'},vector<char>{'.','9','8','.','.','.','3','.','.'},vector<char>{'.','.','.','8','.','3','.','2','.'},vector<char>{'.','.','.','.','.','.','.','.','6'},vector<char>{'.','.','.','2','7','5','9','.','.'}};
//     solveSudoku(test2);
//     printBoard(test2);
// }