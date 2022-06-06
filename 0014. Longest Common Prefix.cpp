#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (auto it = strs.begin() + 1; it != strs.end(); ++it) {
            commonPrefix(prefix, *it, prefix);
        } 
        return prefix;
    }

    // prefix is the prefix variable from the main method
    // s1 is the string from str (const string& ; shouldn't modify it) 
    // s2 is a copy of the `prefix` value from the main method (just const string ; no referense)
    void commonPrefix (string& prefix, const string& s1, const string s2) {
        prefix = "";
        for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
            if (s1[i] == s2[i]) {
                prefix.push_back(s1[i]);
            } else { //MISTAKE: at first I didn't have the else clause here, which caused it to fail some cases (such as with strs = {"car","cir"})
                return;
            }
        }
    }
};

//V2 (more memory efficient)
class Solution {
public:

    //basically, we will begin with the prefix being the first string, and then store the index of the last char within 
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int prefix_size = prefix.size();
        for (auto it = strs.begin() + 1; it != strs.end(); ++it) {

            //if (*it).size() is smaller than the prefix size, then we know the prefix must be at most the size of (*it)
            prefix_size = min(prefix_size, static_cast<int>((*it).size()));
            
            //go through all chars between `prefix` and `str`
            for (int i = 0; i < prefix_size; ++i) {
                
                //once we found a mismatch char, we chop down `prefix` by reducing its size.
                if ((*it)[i] != prefix[i]) {
                    prefix_size = i;
                }
            }
        } 

        //now we return the substring of prefix, matching the size we have recorded.
        return string(prefix.begin(), prefix.begin() + prefix_size);
    }
};