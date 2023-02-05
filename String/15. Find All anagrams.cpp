class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        if(p.size()>s.size()) return {};

        vector<int>freq_p(26,0);
        vector<int>window(26,0);

        for(int i=0; i<p.length(); i++)
        {
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        vector<int>ans;
        if(freq_p == window) ans.push_back(0);
        
        int k = p.length();
        for(int i=p.length(); i<s.length(); i++)
        {
            window[s[i]-'a']++;
            window[s[i-k]-'a']--;
            if(freq_p == window)ans.push_back(i-k+1);
        }
        

        return ans;
        
    }
};


Time Complexity: 0(N)
  Space Complexity: 0(1);
