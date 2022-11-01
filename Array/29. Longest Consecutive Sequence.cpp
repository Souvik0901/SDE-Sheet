
Optimal Approach:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>hashset;
        for(auto it: nums)
        {
            hashset.insert(it);
        }
        
        int longeststreak= 0;
        for(auto it : nums)
        {
            if(!hashset.count(it-1))
            {
                int currentstreak=1;
                int currentnum = it;
                
                while(hashset.count(currentnum+1))
                {
                    currentnum+=1;
                    currentstreak+=1;
                }
                longeststreak= max(longeststreak,currentstreak);
            }
            
        }
        return longeststreak;
    }
};


Brute Force Approach:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
            
        sort(nums.begin(),nums.end());
        int ans =1;
        int count =1;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(prev+1 == nums[i]) count++;
            else if(prev !=nums[i]) count=1;
            
            prev= nums[i];
            ans= max(ans,count);
        }
        return ans;
    }
};
