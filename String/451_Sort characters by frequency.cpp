class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;

        for(auto it: s){
            mp[it]++;
        }

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        string p="";

        while(!pq.empty()){
            p+= string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return p;
    }
};
