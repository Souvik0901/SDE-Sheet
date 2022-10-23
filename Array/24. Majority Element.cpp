
Solution 1: Better Approach
          Time Complexity: 0(N)
          Space Complexity: 0(N)  
            
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        unordered_map<int,int>freq;
        
        for(int i=0; i<nums.size(); i++) freq[nums[i]]++;
        
        for(auto it:  freq)
        {
            if(it.second>nums.size()/3)
                ans.push_back(it.first);
        }
        return ans;
    }
};
