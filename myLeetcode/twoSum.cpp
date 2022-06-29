class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> answer;
        bool answerFound = false;
        for( i = 0; i < nums.size(), answerFound == false; i++ )
        {
            for(j = i + 1; j < nums.size(), answerFound == false; j++ )
            {
               if( target - nums[j] == nums[i] )
               {
                   answer.push_back(i);
                   answer.push_back(j);
                   answerFound = true;
               }
            }
        }
        return answer;
    }
};