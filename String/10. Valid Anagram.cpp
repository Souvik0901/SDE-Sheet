class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int sfreq[26]={0};
        int tfreq[26] ={0};
        for(int i=0; i<s.length(); i++)
        {
            sfreq[s[i]-'a']++;
        }

        for(int i=0; i<t.length(); i++)
        {
            tfreq[t[i]-'a']++;
        }
       
      return  check(sfreq,tfreq);

    }

    bool check(int a[], int b[])
    {
        for(int i=0; i<26; i++)
        {
            if(a[i]!=b[i])
            return false;
        }
        return true;
    }
};


Time Complexity: 0(N);
Space COMplexity: 0(1) , cause two arrays not counted as space is constant
