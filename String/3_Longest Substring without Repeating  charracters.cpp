class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        int length =0;
        int maxlen = 0;
        int j=0;
        unordered_map<char, int>mp;
        for(int i=0; i<s.size();i++){
           mp[s[i]]++;
           length++;

           while(mp[s[i]]>1){
                mp[s[j++]]--;
                length--;
           }

           maxlen = max(maxlen, length);
        }
        return maxlen;
    }
};
