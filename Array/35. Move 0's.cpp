class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       int i=0;
       int j =0;
       while(nums.size()>i and nums.size()>j)
       {
           if(nums[j]!=0)
           swap(nums[i++],nums[j++]);

           else 
            j++;
       }
       

    }
};


TIME Complexity: 0(N);
Space Complexity: 0(1);
