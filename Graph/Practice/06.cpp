#include<bits/stdc++.h>
using namespace std;

int MC(int arr[], int i, int j)
{
    if (i==j) return 0;
    int min = INT_MAX;
    int count =0;
    for(int k = i; k<j; k++)
    {
        count = MC(arr,i, k)+ MC(arr,k+1,j)+ arr[i-1]*arr[k] *arr[j];
        if(count<min)
        min = count;
    }
 return min;
}
int main()
{
    int arr[] = {30, 35, 15, 5 , 10, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
     
     cout<<MC(arr, 1, n-1);
}