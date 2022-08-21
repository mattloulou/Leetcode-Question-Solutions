#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;



class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        // energy:
        const int energyTrained = max(0, accumulate(energy.begin(), energy.end(), 0) - initialEnergy + 1); // i originally didn't max the rhs with 0.
        
        // experience:
        int experienceTrained = 0; // will be the largest difference between currentExperience and experience[i]
        int currentExperience = initialExperience; // not needed, but I wanted to change the variable name
        
        for (int i = 0; i < experience.size(); ++i) {
            experienceTrained = max(experienceTrained, experience[i] - currentExperience + 1);
            currentExperience += experience[i];
        }


        return energyTrained + experienceTrained;
    }
};