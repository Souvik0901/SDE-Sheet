class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid = low+ (high-low)/2;
            if(nums[mid]== target)return mid;

            //left side is sorted or not
            if(nums[low]<=nums[mid])
            {
                //yes, target lies on left side
                if(nums[low]<=target and nums[mid]>=target)
                    high= mid-1;
                else
                    low = mid+1; 
            } 
            //right side is sorted or not
            else
            {
                //yes, target lies on right side
                if(nums[high]>=target and nums[mid]<=target)
                    low =mid+1;
                else
                    high= mid-1;
            }
        }
        return -1;
    }
};
