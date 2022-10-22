



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
