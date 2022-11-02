class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        int result = 1;
        
        for(int i = 5; i < 10000 && result != 0; i = i*5)
        {
            result = n / i;
            zeros += result;
        }
        
        return zeros;
    }
};