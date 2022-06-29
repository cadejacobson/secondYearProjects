class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> answer;
        bool answerFound = false;
        for( i = 0; i < nums.size() && answerFound == false; i++ )
        {
            for(j = i + 1; j < nums.size() && answerFound == false; j++ ) 
            {                           //begin after i's position since the indices must be unique
               if( target - nums[j] == nums[i] )
               {
                   answer.push_back(i); //add the indices of the answers to the vector and return it
                   answer.push_back(j);
                   answerFound = true;
               }
            }
        }
        return answer;
    }
};