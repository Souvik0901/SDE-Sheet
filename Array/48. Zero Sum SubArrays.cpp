// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<int>zeroSumSubarrays(vector<int>&arr){
    unordered_map<int, vector<int>>mp;
    mp[0].push_back(-1);
    vector<int>result;
    int prefixsum =0;
    
    for(int i=0; i<arr.size(); i++){
        prefixsum+=arr[i];
        if(mp.find(prefixsum)!=mp.end()){
            for(auto it: mp[prefixsum]){
                result.push_back(it+1);
            }
            
        }
        mp[prefixsum].push_back(i);
    }
    return result;
}


int main() {
    vector<int> arr = {5,-2,-3,5,0};
    vector<int> result = zeroSumSubarrays(arr);

    cout << "Starting indices of zero sum subarrays:" << endl;
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;

}
