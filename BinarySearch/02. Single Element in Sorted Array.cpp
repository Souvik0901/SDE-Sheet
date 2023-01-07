

Time Complexity: 0(logN)
Space Complexity: 0(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int low=0;
        int high = nums.size()-1;

        if(high ==0 or nums[0]!=nums[1])return nums[0];
        

        while(low<high)
        {
            int mid = low+ (high-low)/2;

           if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])return nums[mid];
           if(nums[low]==nums[low+1] and nums[high]==nums[high-1])
           {
               low+=2;
               high-=2;
           }
           else
           {
               if(nums[low]!=nums[low+1])return nums[low];
               else return nums[high];

           }
           
        }
        return -1;
        
    }
};
