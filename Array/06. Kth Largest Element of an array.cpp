

Approach 1:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()-k];
    }
};


Approach 2:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        
        priority_queue<int>pq(nums.begin(),nums.end());
        
        for(int i=0; i<k-1; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};


Approach 3:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {     
       priority_queue<int,vector<int>, greater<int>>pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
            if(k <pq.size())
                pq.pop();   
                
        }
        return pq.top();
    }
};
