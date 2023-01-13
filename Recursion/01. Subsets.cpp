

class Solution {
public:

    void subset(int i, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums)
    {

        if(nums.size()==i)
        {
           ans.push_back(ds);
           return;
        }
        
        ds.push_back(nums[i]);      //take or pick , particular index into the subsequences
        subset(i+1,ds,ans,nums);
        
        ds.pop_back();             //not take or not pick condition
        subset(i+1,ds,ans,nums);
         
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        int index =0;
        
        //This is the Function for returning all stored subsets in ans
        subset(index,ds,ans,nums);

        return ans;

    }
};


