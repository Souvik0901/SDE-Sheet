class Solution {
public:


    void findcombination(int index, int target, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans)
    {

        if(index== nums.size()) 
        {
            if( target==0)
                ans.push_back(ds);
        
            return;
        }

         if(target>= nums[index])
         {
             ds.push_back(nums[index]);
             findcombination(index,target-nums[index],nums,ds,ans);
             ds.pop_back();
         }

         findcombination(index+1,target,nums,ds,ans);
    }






    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,candidates,ds,ans);

        return ans;
    }
};




Time Complexity:
