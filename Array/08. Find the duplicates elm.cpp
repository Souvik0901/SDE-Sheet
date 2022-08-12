
Approach 1:

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        vector<int>arr(nums.size(),0);   
        
        for(int i=0; i<nums.size(); i++)
        {
            arr[nums[i]]++;
        }
        for(int i=0; i<arr.size();i++)
        {
            if(arr[i]>1)
                return i;
        }
        return -1;
    }
};



Approach 2:

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int>freq;
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        for(auto it: freq)
        {
            if(it.second>1)
                return it.first;
        }
        return -1;
    }
};
  
