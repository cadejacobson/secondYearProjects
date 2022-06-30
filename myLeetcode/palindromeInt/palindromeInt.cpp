public:
    bool isPalindrome(int x) {
        int i, j;
        int size;
        
        if ( x < 0 )
            return false;
        
        string s = to_string( x ); //convert to string so that each element can be accessed
        size = s.size();    //call size here to improve loop efficiency
        
        if( size == 1 )
            return true;
        
        for( i = 0, j = size - 1; i < (size / 2); i++, j--)
        {                   //only half of the digits need to be checked
            if( s[i] != s[j] )
                return false;
        }
        
        return true;
    }
};