class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, left;
        //breaking point
        for(i = nums.size()-2; i>=0; i--){
            if(nums[i] <nums[i+1])
            break;  
        }

        //reverse if you come to end permutation
        if(i<0){
            reverse(nums.begin(), nums.end());
        }
       
        // not the end permutation
        else{
            for(left=nums.size()-1; left>=0; left--)
            {
                if(nums[i]<nums[left])
                    break;
            }
            swap(nums[i], nums[left]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }

};

__________________________________________________________
