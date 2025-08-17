int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, -1);
    int n = s.length();
    int low =0;
    int high =0;
    int maxlen =0;

    while(high < n){
      if(mp[s[high]]!= -1){
        if(mp[s[high]]>= low){
            low = mp[s[high]]+1; 
        }
      }
      maxlen = max(maxlen, high-low+1);
      mp[s[high]]= high;
      high++;
    }
    return maxlen;
}

//Time Compplexity: 0(N)
//Space Complexity: 0(N)

-----------------------------------------------------------------------
//Uisng MAP

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;  // map to store last index of char
    int n = s.length();
    int low = 0, high = 0, maxlen = 0;

    while (high < n) {
        if (mp.find(s[high]) != mp.end() && mp[s[high]] >= low) {
            // move low just after the last occurrence
            low = mp[s[high]] + 1;
        }

        mp[s[high]] = high; // update last index of this char
        maxlen = max(maxlen, high - low + 1);
        high++;
    }

    return maxlen;
}

-----------------------------------------------------------------------
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxlen = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;
        for (int j = i; j < n; j++) {
            if (seen.find(s[j]) != seen.end()) {
                // duplicate found, stop expanding
                break;
            }
            seen.insert(s[j]);
            maxlen = max(maxlen, j - i + 1);
        }
    }

    return maxlen;
}

//Time Complexity: 0(N^2)



