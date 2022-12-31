
Brute Force Approach:

        Time Complexity : 0(n^2)
        Space Complexity: 
#include <bits/stdc++.h> 
using namespace std;
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long int count =0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j]) count++;
        }
    }
    return count;
}



#include <bits/stdc++.h>  
long long getInversions(long long *arr, int n)
{    
  set<long long> s;   
  vector<long long> ans(n,0); //to store number of elements on the right side which are smaller than the current element   
     for(long long i=n-1;i>=0;i--)   
     {       
       s.insert(arr[i]);        
       long long it=distance(s.begin(),s.find(arr[i]));      
       ans[i]=it;   
     }   
     long long a=0;    
     for(long long i=0;i<n;i++)   a+=ans[i];  
  
 return a; 
}
