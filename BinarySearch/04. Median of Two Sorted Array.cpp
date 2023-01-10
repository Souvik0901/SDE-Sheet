class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m =nums2.size();
        int i= 0;
        int j = 0;
        int k = 0;
        int nums[n+m];
        while(i<n and j<m){

            if(nums1[i]<nums2[j])
                   nums[k++] = nums1[i++];
            else 
                   nums[k++] = nums2[j++];
        }
       
            while(i<n)
            {
               nums[k++] = nums1[i++];
            }
        

            while(j<m)
            {
               nums[k++] = nums2[j++];
            }

         n = n+m;
        if(n%2==0) return (double)(nums[n/2] + nums[(n/2)-1])/2;
        else 
        return (double) nums[n/2];

        
    }
};

Time Complexity: 0(M+N);
Space Complexity: 0(M+N);
