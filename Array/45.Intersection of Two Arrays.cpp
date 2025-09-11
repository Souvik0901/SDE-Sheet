class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int num: nums1){
            mp[num]++;
        }
        for(int num: nums2){
            if(mp.find(num)!=mp.end()){
                ans.push_back(num);
                mp.erase(num);
            }
        }
        return ans;
    }
};

________________________________________________________________________
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(), nums1.end());
        unordered_set<int>set2;

        for(auto it: nums2){
            if(set1.find(it) != set1.end()){
                set2.insert(it);
            }
        }
        return vector<int>(set2.begin(), set2.end());

    }
};
