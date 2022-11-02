class Solution {
public:
    int reverse(int x) {
    double val = 0.0;
    int remainder;

    while( x != 0 )
    {
        val *= 10;
        if(val > 2147483647 || val < -2147483648)
            return 0;
        remainder = x % 10;
        val += remainder;
        x = x / 10;
    }

    return int(val);
    }
};