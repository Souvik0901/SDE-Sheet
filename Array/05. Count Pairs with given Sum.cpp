

>> Brute Force Approach : 1
      Time Complexity: 0(N*N)
      Space Complexity: 0(1)
  
>> Code:
  
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count= 0;
        
          for(int i=0; i<n; i++)
          {
              for(int j=i+1; j<n; j++)
              {
                  if(arr[i]+arr[j]==k)
                  count++;
              }
          }
        return count;
    }
};


>> Optimized Using map: 2

      Time Complexity: 0(N)
      Space Complexity: 0(1)
        
        
>> Code:

class Solution
{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
       int count= 0;
       unordered_map<int, int>mp;
       for(int i=0; i<n; i++)
       {
           mp[arr[i]]++;
       }
       for(int i=0; i<n; i++)
       {
          if(mp[k-arr[i]]>0)
          {
            mp[arr[i]]--;
            count+=mp[k-arr[i]];
          }
          
       }
        return count;
    }
};


>> Optimized Using map: 3
  
     Time Complexity: 0(N)
     Space Complexity: 0(1)
       
>> Code:


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count= 0;
        unordered_map<int, int>mp;
          for(int i=0; i<n; i++)
          {
              if(mp.find(k-arr[i])!=mp.end())
              {
                 count+= mp[k-arr[i]];
              }
              mp[arr[i]]++;
          }
        return count;
    }
};


