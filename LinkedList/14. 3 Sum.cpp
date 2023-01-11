Brute Force Approach:
Time Complexity: 0(N^3)
Space Complexity: 0(1)
  
  Time Limit Exceeded

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0 or n<3) return{};
        set<vector<int>>s;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    s.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};


