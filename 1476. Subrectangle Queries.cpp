#include <vector>
using namespace std;
class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->matrix = rectangle;
    }
    
    //note that row1 <= row2 and col1 <= col2 as given in the question.
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
       for (int i = row1; i <= row2; ++i) { //MISTAKE: should be <=    , not <
           for (int j = col1; j <= col2; ++j) { //MISTAKE: should be <=    , not <
               this->matrix[i][j] = newValue;
           }
       } 
    }
    
    int getValue(int row, int col) {
        return this->matrix[row][col];
    }
private:
    vector<vector<int>> matrix;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */