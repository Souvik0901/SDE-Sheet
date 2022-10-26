Solution 

Approach 1: Brute Force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target )
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
                
            }
            if(ans.size()==2)break;
        }
        return ans;
        
    }
};


Approach 2: Hashing(Most Efficient)
  Time Complexity: 0(N)
  Space Complexity: 0(N)
  
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
}
