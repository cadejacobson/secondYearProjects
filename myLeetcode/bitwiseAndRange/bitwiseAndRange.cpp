class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int i;
      for(i = 0; left != right; left >>=1, right >>=1){
         i++;
      }
      return left << i;
    }
};