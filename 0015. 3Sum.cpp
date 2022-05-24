#include <vector>
#include <unordered_map>
#include <algorithm>
// #include <iostream>
using namespace std;

class Solution {
public:

    //requires `largest` to be sorted ascendingly
    bool ContainsTriplet(vector<vector<int>>& triplets, const int& smallest, const int& middle, const int& largest) {
        for (const auto& triplet : triplets) {
            if (triplet[0] > smallest) return false;
            if (triplet[0] == smallest && triplet[1] == middle && triplet[2] == largest) return true;
        }
        return false;
    }

    //only leaves two of each element at most remaining in the vector (except for 0s which can have 3).
    //Returns the size of the new vector (garbage is left in the remaining elements of the vector past `nums.begin() + return` inclusive)
    //expects the given vector `nums` to be sorted to work properly
    int MaxTwoPerUniqueElement(vector<int>& nums)
    {
        const int vector_size = nums.size();
        if (vector_size < 3) return vector_size;

        int new_vector_end_index = 2; //this is the index right after the vector's end. This is similar to vector::end();
        int current_index = 2; //this is the index we are at in our search
        while (new_vector_end_index < vector_size && current_index < vector_size) {

            //add the element to the end of the vector if:
            if ((nums[current_index] != nums[new_vector_end_index-2]) //if the current element differs from the second last element in the new vector 
                || (nums[current_index] == 0 && (new_vector_end_index < 3 || nums[new_vector_end_index-3] != 0))) //if the current element is 0 and differs from the third last element
            {
                nums[new_vector_end_index++] = std::move(nums[current_index]);
            }
            ++current_index;
        }
        const int& new_size = new_vector_end_index;        
        return new_size;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        //we begin by sorting nums, and then removing any duplicate elements above 2 duplicates (except for 0, as 3x 0s sum to 0, but not for any other nums).
        sort(nums.begin(), nums.end());
        int vector_size = MaxTwoPerUniqueElement(nums);

        //the set of (set of 3 values (can't be from the same index)) that sum to 0.
        vector<vector<int>> solution;

        //Algorithm:
        //for each element in nums, we will do the 2sum solution for finding 2 numbers that sum to -1*nums[i];
        for (int i = 0; i < vector_size; ++i) {
            //in the potential triplets we are searching for, we are assuming nums[i] will be a part of it.
            //So, 2 other elements in nums must sum to -1*nums[i]
            const int remaining_sum = -1*nums[i]; 

            //now perform the 2sum algorithm
            unordered_map<int, int> values_and_indices{}; // {values found in nums, their indices}
            for (int j = i+1; j < vector_size; ++j) {
                const int other_required_number = remaining_sum - nums[j];

                //check if the missing number has been found so far
                if (values_and_indices.count(other_required_number) //the other number is found
                    && values_and_indices.at(other_required_number) != i && i != j && j != values_and_indices.at(other_required_number)) { //they are all unique indices
                    
                    const int& smallest_num = nums[i];
                    const int& middle_num = other_required_number;
                    const int& largest_num = nums[j];

                    //we need to make sure that we don't have duplicate solutions (question statement requires it).
                    if (!ContainsTriplet(solution, smallest_num, middle_num, largest_num)) {
                        solution.emplace_back(vector<int>{smallest_num, middle_num, largest_num}); 
                    }                       
                    
                //if it has not been found yet, insert it. This helps to make sure that we don't count 
                } else {
                    values_and_indices.emplace(nums[j], j);
                }
            }
            values_and_indices.clear(); //reset map because we are trying to achieve a new sum now.
        }
        return solution;
    }
};

//testing program for MaxTwoPerUniqueElement()

// int main() {
//     vector<int> test{-1,0,1,-1,2,-1,-4,0,0,0};
//     sort (test.begin(), test.end());
//     Solution* s = new Solution();
//     int new_size = s->MaxTwoPerUniqueElement(test);

//     //we expect for all elements to be capped at 2, except for `0`s at 3.
//     for (int i = 0; i < new_size; ++i) {
//         cout << test[i] << " ";
//     }
//     delete s;
// }