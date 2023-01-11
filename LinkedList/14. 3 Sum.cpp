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


Optimal Approach : 
Time Complexity: 0(n^2)
space Complexity: 0(1)
  
  
  class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2;i++)
        {
            if(i==0 or i>0 and nums[i]!=nums[i-1]) //this condition will take care of duplicate a
            {
                int left = i+1;
                int right = nums.size()-1;
                int target =0;
                target-=nums[i];
                while(left<right)
                {
                   if(nums[left]+nums[right] ==target)           // condition for target is equal
                   {
                       res.push_back(vector<int>{nums[i],nums[left], nums[right]}); //triplet is add in ans.
                       left++;
                       right--;

                       while(left<right and nums[left]==nums[left-1])   //this condition will take care duplicate b
                         left++;
                       
                       while(left<right and nums[right]== nums[right+1])  //this condition will take care duplicate c
                        right--;

                   }

                   else if(nums[left]+nums[right] <target)left++;  // if target is greater 
                   else right--;                                   // condition for target is smaller
                }
            }
        }
        return res;
    }
};
