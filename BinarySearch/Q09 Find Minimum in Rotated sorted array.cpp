class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low =0;
        int high = nums.size()-1;
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
          
            if(nums[high]>nums[mid])
               high= mid;
            else
               low = mid+1;
        
        }

        return nums[low];
    }
};
