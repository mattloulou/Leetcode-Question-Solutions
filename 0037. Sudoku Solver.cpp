//Similar to: SAC '22 Code Challenge 5 Junior P5 - English Summative.cpp

#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    pair<int,int> firstUnsolvedTile(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') return pair<int,int>{row,col};
            }
        }
        return pair<int,int>{-1,-1};
    }

    void fillInKnownTiles(vector<vector<char>>& board, queue<pair<int,int>>& solved_tiles, vector<vector<unordered_set<char>>>& possible_numbers) {
        //we will keep going through our solved tiles list and find which ones are now known
        while (!solved_tiles.empty()) {
            
            //get the tile information
            pair<int,int> tile = solved_tiles.front();
            const int& row = tile.first;
            const int& col = tile.second;
            const char& tile_value = board[row][col]; 
            solved_tiles.pop();

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
                        solved_tiles.emplace(row,i);
                    }
                }

                //VERTICAL
                //make sure it is not the same tile
                if (i != row) {
                    possible_numbers[i][col].erase(tile_value);

                    //if the tile just has 1 possibility left, it is solved.
                    if (possible_numbers[i][col].size() == 1 && board[row][i] == '.') {
                        board[i][col] = *(possible_numbers[i][col].begin()); //set the value to the last remaining possible number.
                        solved_tiles.emplace(i,col);
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
                        solved_tiles.emplace(sub_box_row,sub_box_col);
                    }
                }

            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        //this will be done using topological sort I believe.

        const unordered_set<char> all_numbers = {'1','2','3','4','5','6','7','8','9'};
        vector<vector<unordered_set<char>>> possible_numbers(9, vector<unordered_set<char>>(9, all_numbers));
        queue<pair<int /*row*/, int /*col*/>> solved_tiles;

        //now, we will go through the given board and see which tiles are already given.
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                const char tile_value = board[i][j];
                if (tile_value != '.') {
                    // possible_numbers[i][j].clear();
                    // possible_numbers[i][j].insert(tile_value);
                    solved_tiles.emplace(i, j);
                }
            }
        }

        while (true) {
            fillInKnownTiles(board, solved_tiles, possible_numbers);
            pair<int,int> first_unsolved_tile = firstUnsolvedTile(board);
            const int& row = first_unsolved_tile.first;
            const int& col = first_unsolved_tile.second;

            //we are done
            if (row == -1) {
                return;

            //we must make a guess
            } else {
                board[row][col] = *(possible_numbers[row][col].begin()); 
                solved_tiles.emplace(row,col);
            }
        }
    }
};