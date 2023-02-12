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

Time Complexity: 0(N^2)
