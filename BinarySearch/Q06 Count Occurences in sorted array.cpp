

Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.









#include<bits/stdc++.h>
using namespace std;

int lowerbound(int arr[], int n, int target){
    
    int low = 0;
    int high = n-1;
    
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
         if(arr[mid] >=target){
         ans = mid;
         high = mid-1;
         }

         else low = mid+1;
    }
  return ans;

}


int upperbound(int arr[], int n, int target){
    
    int low = 0;
    int high = n-1;
    
    int ans = -1;
    while(low<=high){
         int mid = (low+high)/2;
         if(arr[mid] <=target){
         ans = mid;
         low = mid+1;
         }

         else high = mid-1;
    }
  return ans;

}





pair<int,int>getFirstSecondOccr(int arr[], int n, int target){
        int i= lowerbound(arr,n,target) ;
        int j= upperbound(arr,n,target) ;

        return make_pair(i,j);
}

int count (int arr[], int n, int target){
    pair<int,int> ans = getFirstSecondOccr(arr,n,target);
    if(ans.first == -1) return 0;
    return (ans.second - ans.first+1 );
}


int main(){

    int n =7;
    int arr[n]={3,4,13,13,13,20,40};
    int target = 13;

    //pair<int,int>ans = getFirstSecondOccr(arr,n,target);
    //cout<<ans.first<<" "<<ans.second;

    int ans = count(arr, n, target);
    cout<<ans;
}
