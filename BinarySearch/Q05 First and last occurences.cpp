
Example 1:
Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
Output: 2, 4
Explanation: As the target value is 13 , it appears for the first time at index number 2.

Example 2:
Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
Output: -1,-1
Explanation: Target value 60 is not present in the array 










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


int main(){

    int n =7;
    int arr[n]={3,4,13,13,13,20,40};
    int target = 13;
    pair<int,int>ans = getFirstSecondOccr(arr,n,target);
    cout<<ans.first<<" "<<ans.second;
}
