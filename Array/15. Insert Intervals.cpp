class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
     {
        intervals.push_back(newInterval);

         if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end());

        int j =0;
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0] <= ans[j][1]) 
                ans[j][1]= max(ans[j][1],intervals[i][1]);

            else 
            {
                j++;
                ans.push_back(intervals[i]);
            }

        }
       return ans;
    }
};
