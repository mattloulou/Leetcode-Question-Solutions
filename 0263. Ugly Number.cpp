class Solution {
public:
    bool isUgly(int n) {

        if (n <= 0) return false; // given in the question

        while (n % 5 == 0) n /= 5;
        while (n % 3 == 0) n /= 3;
        while (n % 2 == 0) n /= 2;
        
    
        return n==1;
    }
};

// V2 the same solution, but actually more optimized
class Solution {
public:
    bool isUgly(int n) {

        if (n <= 0) return false; // given in the question
        
        while (n % 25 == 0) n /= 25;
        while (n % 5 == 0) n /= 5;
        while (n % 9 == 0) n /= 9;
        while (n % 3 == 0) n /= 3;
        while (n % 4 == 0) n /= 4;
        while (n % 2 == 0) n /= 2;
        
    
        return n==1;
    }
};