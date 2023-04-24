class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()==0) return intervals;

        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        int j =0;
        for(int i=1; i<intervals.size(); i++){

            if(intervals[i][0]<=ans[j][1])
            ans[j][1]= max(ans[j][1], intervals[i][1]);

            else{
                j++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};


Time complexity:
Time Complexity : O(NlogN), Sorting the array(intervals) costs O(NlogN). Where N is the size of the Vector(intervals).

Space complexity:
Space Complexity : O(1), Constant Space. Extra space is only allocated for the Vector(output) which can go upto size N , however the output does not count towards the space complexity.
