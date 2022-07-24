#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> mp; // {cuisine, set(<rating, food>)}
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            const string& food = foods[i];
            const string& cuisine = cuisines[i];
            const int& rating = -ratings[i];
            mp[cuisine].insert({rating,food});
            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
        }
    }


    // always insert ratings as negative so that the set<pair<int,string>> in mp is ordered automatically. Since set orders by smallest first by default,
    // the pair with the smallest rating will be first (so if we insert ratings as negative, the smallest will actually be the largest). If two
    // ratings are equal, the pair with the smallest string will come first.
    void changeRating(string food, int newRating) {

        // update foodToRating
        int currentRating = foodToRating[food];
        foodToRating[food] = -newRating;

        // update mp
        mp[foodToCuisine[food]].insert({-newRating,food});
        mp[foodToCuisine[food]].erase({currentRating,food});
    }
    
    string highestRated(string cuisine) {
        // return the food for the first element in mp[cuisine]
        return (*(mp[cuisine].begin())).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */