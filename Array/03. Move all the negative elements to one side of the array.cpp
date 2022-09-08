

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<int>nums;
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]<0)
            {
                nums.push_back(arr[i]);
            }
            else
            {
                 arr[j++]=arr[i];
            }
        }
        
        
        int neg=0;
        for(int k=j;k<n; k++)
        {
            arr[k]=nums[neg++];
        }
           
    }
};



