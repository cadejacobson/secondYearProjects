class Solution {
public:
    string longestPalindrome(string s) {
        int i, j;
        size_t stringSize = s.size();
        string reversedShort, shortened = s;
        int maxSize = 1;
        string palindrome;
        
        if( stringSize == 1 )
            return shortened;
        
        if( reverseString(s) == s )
            return s;
        
        for(i = 0; i < stringSize; i++)
        {
            for(j = 0; j < stringSize; j++)
            {
                shortened = s.substr(i,j);
                reversedShort = reverseString(shortened);
                if( shortened == reversedShort && shortened.size() > maxSize )
                {
                    maxSize = shortened.size();
                    palindrome = shortened;
                }
            }
        }
        
        return palindrome;
    }
    string reverseString(string s)
    {
        int i;
        size_t length = s.size();
        for(i = 0; i < length / 2; i++)
            swap(s[i], s[length - i - 1]);
        return s;
    }
};