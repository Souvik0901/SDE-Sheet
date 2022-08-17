Approach 1:
class Solution{
public:
    int *findTwoElement(int *arr, int n) 
    {
        // code here
        int *nums= new int[2];
        map<int, int>freq;
        for(int i=1; i<=n; i++)
        {
            freq[i]++;
        }
        for(int i=0; i<n; i++)
        {
            freq[arr[i]]--;
        }
        for(auto it: freq)
        {
            if(it.second==-1) nums[0]=it.first;
            if(it.second==1) nums[1]=it.first;
        }
        
        return nums;
    }
};


Approach 2:
class Solution{
public:
    int *findTwoElement(int *arr, int n) 
    {
        int *ans=new int[2];
       map<int,int> mp;
       for(int i=0;i<n;i++) {
           mp[arr[i]]++;
       }
       for(int i=1; i<=n; i++) {
          if(mp[i] == 2) ans[0] = i;
          if(mp[i] == 0) ans[1] = i;
       }
       return ans;
    }
};
