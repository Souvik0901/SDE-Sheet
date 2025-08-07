class Solution {
public:
    string longestPalindrome(string str) {
        if(str.length()<=1)return str;
        int max_len = 1;
        string max_str= str.substr(0, 1);

        for(int i=0; i<str.length(); i++){
            for(int j= max_len+i; j<=str.length(); j++ ){
                if( j-i > max_len && isPallindrome(str.substr(i,j-i))){
                    max_len = j-i;
                    max_str = str.substr(i, max_len);
                }
            }
        }
        return max_str;
    }

    bool isPallindrome(string str){
        int left = 0;
        int right = str.length()-1;
        while(left<right){
            if(str[left]!=str[right])return false;
            left++;
            right--;
        }
        return true;
    }
};

//Time-Complexity: 0(N^3)
------------------------------------------------------------------------------------------------


//Dynamic Programming Solve

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        // Step 1: Create a 2D DP table initialized with false
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int maxLen = 1;
        int start = 0;

        // Step 2: All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Step 3: Check for substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Step 4: Check for substrings of length 3 and more
        for (int len = 3; len <= n; ++len) {  // len is the length of substring
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index

                // Check if characters match and the inner substring is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        // Step 5: Return the longest palindromic substring
        return s.substr(start, maxLen);
    }
};

//Time Complexity- 0(N^2)
-----------------------------------------------------
