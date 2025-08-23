// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void subfunc(vector<int>&arr, vector<int>&ds, int targetsum, int index, int sum){
    if(index>=arr.size()){
        if(sum == targetsum){
            for(auto it:ds ){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    
    subfunc(arr, ds, targetsum, index+1, sum+=arr[index]);
    ds.push_back(arr[index]);
    subfunc(arr, ds, targetsum, index+1, sum-=arr[index]);
    ds.pop_back();
    
}

int main() {
    vector<int> arr = {1, 2, 1};
    int targetsum =2;
    vector<int>ds;
    subfunc(arr,ds,targetsum,0,0);
    
}
