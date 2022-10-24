
Approach 1:
      Recursion
      
           But it will give Time Limit Exceeded.
Code:
class Solution {
public:
    
    int solve(int i, int j, int m, int n)
    {
        if(i==(m-1)and j==(n-1)) return 1;
        if(i>=m || j>=n) return 0;
        else
        {
            return solve(i+1,j,m,n)+solve(i,j+1,m,n);
        }
    }
    
    int uniquePaths(int m, int n) 
    {  
       return solve(0,0,m,n);
    }
};


Approach 2: Memorization+ DP

Time Complexity : 0(m*n)
Space Complexity: 0(m*n), As we are using extra space for the dummy matrix. 

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if(i>=m || j>=n)return 0;
        if(i==(m-1) and j==(n-1))return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};
      

Approach 3: Combinatorics Method
Time Complexity: 0(m-1) or 0(n-1)
Space Complexity: 0(1)

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
