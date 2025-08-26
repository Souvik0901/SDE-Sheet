#include <bits/stdc++.h>
using namespace std;

int countWays(int n) {
    vector<int> dp(n+1, 0);

    // Base cases
    dp[0] = 1;  // 1 way to stay at ground
    if(n >= 1) dp[1] = 1;  
    if(n >= 2) dp[2] = 2;  

    // Fill dp table
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    cout << "Number of ways: " << countWays(n) << endl;
    return 0;
}



//time complexity: 0(N)
//Space Complexity: 0(N)
_____________________________________________________
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
         vector<int> dp(n+1, 0);
         dp[0]= 1;
         dp[1] = 1;  
    
         for(int i=2; i<=n; i++){
            dp[i]= dp[i-1]+dp[i-2];
         }
         return dp[n];
    }
};
