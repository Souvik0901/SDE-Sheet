

Approach 1: Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans =0;
        for(int i=0; i<nums.size(); i++)
        {
            int sum = nums[i];
            if(sum==k) ans++;
            for(int j=i+1; j<nums.size(); j++)
            {
                sum+=nums[j];
                if(sum==k)
                    ans++;
            }
        }
        return ans;
    }
};

Approach 2: Optimal Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int>mp;
        int sum =0;
        int ans =0;
        mp[sum]=1;
        
        for(auto it : nums)
        {
            sum+=it;
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];   
            
             mp[sum]++;
        }
     
        return ans;
    }
};
