class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans =0;
        for(int i=1; i<=nums.size(); i++){
           ans = ans^i;
        }
        for(int i=0; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};

//TIme Complexity: 0(N)
//Space Complexity: 0(1)
