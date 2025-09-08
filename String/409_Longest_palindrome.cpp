class Solution {
public:
    int longestPalindrome(string s) {
        int oddcount = 0;
        int evencount = 0;
        unordered_map<char, int>mp;
        for(int i=0; i<s.length(); i++){
           mp[s[i]]++;
        }

        for(auto it: mp){
            if(it.second %2 ==0) evencount+=it.second;
            else {
                evencount+=it.second-1;
                oddcount=1;
            }
        }

        return evencount + oddcount;
    }
};


_______________________________________________________
