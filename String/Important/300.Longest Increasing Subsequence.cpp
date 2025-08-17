class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int size = nums.size();
        vector<int>dp(size,1); // initialize a dp

        for(int i=1; i<size; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                dp[i]= max(dp[i], dp[j]+1);
            }
        }

        return *max_element(dp.begin(), dp.end());


    }
};
