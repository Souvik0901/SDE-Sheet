class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int start = 0;
        int end = height.size()-1;

        int mx_area =-1;

        while(start<end)
        {
            mx_area = max(mx_area, min(height[start],height[end])*(end-start));
            if(height[start]<height[end]) start++;
            else end--;
        }
        return mx_area;
        
    }
};
