#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowResults(k+1,-1), colResults(k+1,-1); // ignore index 0
        vector<unordered_set<int>> analyzedRowConditions(k+1), analyzedColConditions(k+1); // the set at index `i` contains all integers which int `i` must be above.
          
        // ROWS:
            
        // get the row conditions
        for (const vector<int>& rowCondition : rowConditions) {
            if (rowCondition[0] == rowCondition[1]) return {};
            analyzedRowConditions[rowCondition[0]].insert(rowCondition[1]); // rowCondition[0] must be above rowCondition[1]
        }
        
        // create a priority queue to help find a valid order 
        set<pair<int, int>, Comparator> pq; // this is kinda a priority queue. {integer, numberOfOutstandingConditions}
        for (int i = 1; i <= k; ++i) {
            pq.insert({i, analyzedRowConditions[i].size()});
        }
        
        // try to find a valid order
        int currentIndex = k-1;
        while (pq.size() > 0 && pq.begin()->second == 0) {
            
            // find which integer can be assigned a row
            const int valToRemove = pq.begin()->first;
            rowResults[valToRemove] = currentIndex--;
            unordered_set<int> modifiedValues;
            
            // update the other values
            for (const pair<int,int>& e : pq) {
                bool modified = analyzedRowConditions[e.first].erase(valToRemove);
                if (modified) {
                    modifiedValues.insert(e.first);
                }
            }
            
            for (const int& modified : modifiedValues) {
                pq.erase({modified, analyzedRowConditions[modified].size()+1});
                pq.insert({modified, analyzedRowConditions[modified].size()});
            }
            
            pq.erase({valToRemove, 0});
        }
        
        // check if this was invalid
        if (pq.size() != 0) return {};
        
        // COLS:
        
         // get the col conditions
        for (const vector<int>& colCondition : colConditions) {
            if (colCondition[0] == colCondition[1]) return {};
            analyzedColConditions[colCondition[0]].insert(colCondition[1]); // colCondition[0] must be above colCondition[1]
        }
        
        // create a priority queue to help find a valid order 
        pq.clear(); // this is kinda a priority queue? {integer, numberOfOutstandingConditions}
        for (int i = 1; i <= k; ++i) {
            cout << "pq: " << i << " " << analyzedColConditions[i].size() << endl;
            pq.insert({i, analyzedColConditions[i].size()});
        }
        
        // try to find a valid order
        currentIndex = k-1;
        while (pq.size() > 0 && pq.begin()->second == 0) {
            
            // find which integer can be assigned a col
            const int valToRemove = pq.begin()->first;
            colResults[valToRemove] = currentIndex--;
            unordered_set<int> modifiedValues;
            cout << "valToRemove: " << valToRemove << endl;
            
            // update the other values
            for (const pair<int,int>& e : pq) {
                cout << "vals: " << e.first << endl;
                bool modified = analyzedColConditions[e.first].erase(valToRemove);
                
                if (modified) {
                    cout << "modified " << modified << endl;
                    modifiedValues.insert(e.first);
                }
            }
            for (const int& modified : modifiedValues) {
                pq.erase({modified, analyzedColConditions[modified].size()+1});
                pq.insert({modified, analyzedColConditions[modified].size()});
                cout << analyzedColConditions[modified].size() << endl;
            }
            pq.erase({valToRemove, 0});
        }
        
        // check if this was invalid
        if (pq.size() != 0) return {};
        
        
        // CREATE RESULT
        vector<vector<int>> result(k, vector<int>(k));
        for (int i = 1; i <= k; ++i) {
            cout << rowResults[i] << " " << colResults[i] << endl;
            // result[rowResults[i]][colResults[i]] = i;
        }
        return {{}};
    }
    
    struct Comparator {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) const {
            return a.second < b.second;
        }  
    };
};