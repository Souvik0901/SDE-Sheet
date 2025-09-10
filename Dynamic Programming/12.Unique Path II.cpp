class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0; 
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0]==1?0:1;

        //fill first row
        for(int i=1; i<n; i++){
            dp[0][i] = obstacleGrid[0][i]==1?0: dp[0][i-1];
        }

        //fill the first colmn
        for(int j=1; j<m; j++){
            dp[j][0] = obstacleGrid[j][0]==1?0: dp[j-1][0];
        }

        //fill the rest values
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
              dp[i][j] = obstacleGrid[i][j]==1?0: dp[i-1][j]+dp[i][j-1];
            }
        }

     return dp[m-1][n-1];
    }
};

//Time Complexity: 0(N^2)
//Space Complexity: 0(N)
______________________________________________________________________________
