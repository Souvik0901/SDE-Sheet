class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        int mxlength=0;
        int j=0;
        map<char,int>mp;

        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
            length++;

            while(mp[s[i]]>1){
                mp[s[j++]]--;
                length--;
            }

            mxlength = max(length, mxlength);
        }
        return mxlength;
    }
};


Time Complexity: 0(N);
Space Complexity: 0(N)
