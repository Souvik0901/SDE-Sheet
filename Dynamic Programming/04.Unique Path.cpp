class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m+n-2;
        int right = m-1;
        double ans=1;
        
        for(int i=1; i<=right; i++)
        {
            ans = ans*(total-right+i)/i;
        }
        return (int) ans;
    }
};



_____________________________________________________________________

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Fill the dp table
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    
    }
 //Time Complexity: 0(M*N)
 //Space Complexity: 0(N)

________________________________________________________________________
