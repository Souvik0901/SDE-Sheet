class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int, int> mp;
        for(int it: nums1){
            mp[it]++;
        }
        for(int it: nums2){
            if(mp[it]){
                result.push_back(it);
                mp[it]--;
            }
        }
        return result;
    }
};
