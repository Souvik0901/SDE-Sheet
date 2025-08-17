int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // only start counting if it's the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int cnt = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }

//Time Complexity: 0(N)
//Space Complexity: 0(N) for set
---------------------------------------------------------------------
int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0)return 0;

        sort(nums.begin(),nums.end());
      
        int cnt =1;
        int maxi = 1;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(prev+1==nums[i] )cnt++;
            else if(prev!=nums[i]) cnt=1;
            
            prev = nums[i];
            maxi = max(maxi,cnt);
        }
        return maxi;
}
//Time Complexity: 0(NLogN)
//Space Complexity: 0(1)
__________________________________________________________________________

