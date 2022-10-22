



Optimal Approach: // Moore's voting Algorithm
 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        int Element =0;
        
        for(int i=0; i<n; i++)
        {
            if(count==0) Element= nums[i];
            if(nums[i]==Element)
                count+=1;
            else
                count-=1;
        }
        return Element;
        
    }
};



Approach 2: Using Hashmap,
            Time Complexity: 0(NlogN);
            Space Complexity: 0(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it: nums)
        {
            if(nums.size()/2 < ++freq[it])
                return it;
        }
        return 0;
    }
};
