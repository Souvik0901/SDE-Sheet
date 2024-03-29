class Solution {
public:

    static bool compare(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size()==0) return 0;

        sort(points.begin(), points.end(), compare);


        int arrows =1;
        int last_elm = points[0][1];
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0]>last_elm)
            {
                arrows++;
                last_elm= points[i][1];
            }
        }
        return arrows;
    }
};
