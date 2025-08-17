class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));


        // Base case: every single character is palindrome of length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Step 2: Substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = 2;
            else dp[i][i + 1] = 1;  // each char individually
        }

        //for length of substring 2 or more 
        for(int len =2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j= i + len - 1;
                if(s[i]==s[j]){
                    if(len == 2) dp[i][j] = 2;  // two same chars
                    else dp[i][j] = 2 + dp[i+1][j-1];
                }
            }
        }

        // Step 3: Substrings of length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
