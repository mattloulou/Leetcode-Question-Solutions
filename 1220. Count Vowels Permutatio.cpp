#include <vector>
using namespace std;

// each index represents the vowel (a,e,i,o,u) at the end of a substring 
class Solution {
public:
    int countVowelPermutation(int n) {
        const int modulus = 1000000007;
        vector<unsigned long long> current(5, 1);
        vector<unsigned long long> temp(5);
        int iteration = 1;
        while (iteration < n) {

            /* The reason why we can do the %modulus here and not just at the end when returning our answer is because: 
             * first, think of each index in `current` or `temp` being stored as: n + k*modulus, where n and k are both non-negative integers.
             * Then, each time we do an iteration, each new index will also be some m + j*modulus, for m,j non-negative integers. 
             * However, the summation of the individual k_n*modulus terms will only ever contribute to the new
             * j*modulus term, which will then be deleted when the answer is returned. Thus, we can just remove them now, as they play no effect on the calculations.
             */ 
            temp[0] = (current[1] + current[2] + current[4]) % modulus; // {e,i,u} can be followed by an 'a'
            temp[1] = (current[0] + current[2]) % modulus; // {a,i} can be followed by an 'e'
            temp[2] = (current[1] + current[3]) % modulus; // {e,o} can be followed by an 'i'
            temp[3] = (current[2]) % modulus; // {i} can be followed by an 'o'
            temp[4] = (current[2] + current[3]) % modulus; // {i,o} can be followed by an 'u'
            current = temp;
            ++iteration;
        }
        unsigned long long answer = current[0] + current[1] + current[2] + current[3] + current[4];
        return static_cast<int>(answer % modulus);
    }
};