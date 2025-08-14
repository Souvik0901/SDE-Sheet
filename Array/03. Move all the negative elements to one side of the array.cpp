

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


---------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int>nums= {4,5,6,-2,-1,7,-3,-8,1,3,5,-1};
   int k = nums.size()-1;
   int i =0;
   while(i<=k)
  {
        if(nums[i]<0 && nums[k]>0)  swap(nums[i++], nums[k--]);
        else if(nums[i]<0 && nums[k]<0) k--;
        else {
            i++;   // important fix
        }
   }
   for(int i=0; i<nums.size(); i++){
       cout<<nums[i]<< ",";
   }
}

//Time Complexity: 0(N)
//sapce Complexity: 0(1)
--------------------------------------------------------------------------------




