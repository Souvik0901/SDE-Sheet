

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        intervals.push_back(newInterval);

        if(intervals.size()==0) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>res;
        res.push_back(intervals[0]);

        int temp=0;
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0] <= res[temp][1]) 
               res[temp][1]= max(res[temp][1], intervals[i][1]);
            
            else
            {
                temp++;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
