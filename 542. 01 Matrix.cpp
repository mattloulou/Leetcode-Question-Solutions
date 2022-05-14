#include <vector>
#include <queue>
using namespace std;

//V1: scrapped this solution because it kept getting TLE on some specific cases.
/*
class Solution {
public:
    const int adjacent_elements[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        //this is the maximum possible distance between two elements (opposite corners of matrix)
        const int max_distance = mat.size() - 1   +   mat[0].size() - 1; 

        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), max_distance));

        //iterate through the matrix and call DFS on all elements that are 0
        for (int r = 0; r < mat.size(); ++r) {
            for (int c = 0; c < mat[0].size(); ++c) {
                if (mat[r][c] == 0) {
                    DFS(answer, mat, 0, r, c);
                }
            }
        }
        return answer;

    }

    void DFS(vector<vector<int>>& answer, const vector<vector<int>>& matrix, int fill_value, int row, int col) {
        answer[row][col] = fill_value;
        const int next_fill_value = fill_value + 1;

        //loop through the four adjacent elements and decide if we should call DFS on them too.
        for (const auto& direction : adjacent_elements) {
            const int new_row = row + direction[0];
            const int new_col = col + direction[1];

            //during my first time coding this, I got an error because I forgot to check if (new_row, new_col) was in bounds of the matrix
            if (new_row >= 0 && new_row < answer.size() && new_col >= 0 && new_col < answer[0].size()            //in-bounds conditions
                             && matrix[new_row][new_col] == 1 && answer[new_row][new_col] > next_fill_value) {   //recursive fill conditions
                DFS(answer, matrix, next_fill_value, new_row, new_col);                                          //recursive call
            }
        }
    }
};*/

//V2
/*
class Solution {
public:
    const int adjacent_elements[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), -1));
        int count = 0;
        int current_fill_value = 0;
        const int total_count = mat.size() * mat[0].size();

        //setup the answer 2D vector with the 0 inidices
        for (int r = 0; r < mat.size(); ++r) {
            for (int c = 0; c < mat[0].size(); ++c) {
                if (mat[r][c] == 0) {
                    ++count;
                    answer[r][c] = 0;
                }
            }
        }

        //keep looping through the answer vector until it is fully filled up. 
        //We already have all the 0s, now we will fill in all the 1s, then 2s, etc...
        while (count != total_count) {
            for (int r = 0; r < mat.size(); ++r) {
                for (int c = 0; c < mat[0].size(); ++c) {
                    if (answer[r][c] == current_fill_value) {
                        
                        //check the adjacent elements)
                        for (const auto& direction : adjacent_elements) {
                            const int new_row = r + direction[0];
                            const int new_col = c + direction[1];

                            if (new_row >= 0 && new_row < mat.size() && new_col >= 0 && new_col < mat[0].size() 
                                             && answer[new_row][new_col] == -1) {
                                answer[new_row][new_col] = current_fill_value + 1;
                                ++count;
                            }
                        }                        
                    }
                }
            }
            ++current_fill_value;
        }
        return answer;
    }
}; */

//V3    (like V2 but instead with a queue). Makes it a lot faster
class Solution {
public:
    const int adjacent_elements[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<int,int>> q;

        //find all 0-elements in the matrix and add them to the queue
        for (int r = 0; r < mat.size(); ++r) {
            for (int c = 0; c < mat[0].size(); ++c) {
                if (mat[r][c] == 0) {
                    answer[r][c] = 0;
                    q.emplace(r,c);
                }
            }
        }

        //keep looping through the answer vector until every element has been visited
        //BFS approach I think
        while (!q.empty()) {
            const int r = q.front().first;
            const int c = q.front().second;
            q.pop();
            
            //check the adjacent elements
            for (const auto& direction : adjacent_elements) {
                const int new_row = r + direction[0];
                const int new_col = c + direction[1];

                if (new_row >= 0 && new_row < mat.size() && new_col >= 0 && new_col < mat[0].size() //in bounds condition
                                    && answer[new_row][new_col] == -1) {                            //not yet visited condition
                    answer[new_row][new_col] = answer[r][c] + 1; //the unvisited neighbour should have a distance 1 greater than its neighbour.
                    q.emplace(new_row,new_col);
                }
            }
        }
        return answer;

    }
};