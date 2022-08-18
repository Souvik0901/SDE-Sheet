Time Complexity: 0(Nlogn)+0(N)
Space Complexity: 0(N)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        if(intervals.size()==0)
            return intervals;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        
        int j=0;
        for(int i=1; i<intervals.size();i++)
        {
            if(intervals[i][0]<=ans[j][1]) 
                ans[j][1]= max(intervals[i][1],ans[j][1]);
            else
            {
                 j++;
                ans.push_back(intervals[i]);
            }
          
            
        }  
        
        return ans;
    }
};
