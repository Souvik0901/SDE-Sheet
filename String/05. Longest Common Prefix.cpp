class Solution {
public:
    string longestCommonPrefix(vector<string>& s) 
    {
        int ans = s[0].length();
        int n = s.size();
      
        for(int i=1; i<n; i++)
        {
            int j =0;
            while(s[i].length()>j  and   s[0][j] == s[i][j]) 
                j++;

            ans = min(ans,j);
        }
        return s[0].substr(0,ans);
    }
};
