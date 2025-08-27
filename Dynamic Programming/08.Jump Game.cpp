bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false; // Cannot proceed further
        maxReach = max(maxReach, i + nums[i]);
        if (maxReach >= nums.size() - 1) return true; // Reached or surpassed last index
    }
    return false;
}

--------------------------------------------------------

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true; // start position is always reachable
    
    for (int i = 0; i < n; i++) {
        if (dp[i]) { 
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = true;
            }
        }
    }
    return dp[n - 1];
}

___________________________________________________________________
