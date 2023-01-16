
Solution 1: Using Recursion
  T.C - 0(n!*n)
  S.C- 0(n)+0(n), for ds and map.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool>freq(nums.size(),false);

        FindPermute(nums,ds,ans,freq);
        return ans;
    }

    void FindPermute(vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans, vector<bool>&freq)
    {
        if(ds.size()== nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]= true;
                FindPermute(nums,ds,ans,freq);
                freq[i]=false;
                ds.pop_back();
            }
        }
    }
};






Solution 2: Using Backtracking
 T.C - 0(n!* n)
 S.C- 0(1)
 
  
  
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {   
        vector<vector<int>>ans;
        FindPermute(0,nums,ans);
        return ans;
    }

    void FindPermute(int index, vector<int>&nums, vector<vector<int>>&ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i= index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            FindPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
};
 
