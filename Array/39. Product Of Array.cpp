class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
       vector<int>ans(nums.size());
        
       int prefix =1;
       int postfix =1;
       for(int i=0; i<nums.size(); i++)
       {
           ans[i]= prefix;
           prefix*=nums[i];
       }
       
       for(int i=nums.size()-1; i>=0; i--)
       {
           ans[i]*= postfix;
           postfix*=nums[i];
       }
    
        return ans;
    }
};

T.C 0(N)
Space Complexity: 0(N)
