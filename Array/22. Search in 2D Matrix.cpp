
Optimal Approach:  Time Complexity: 0(N)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int columns= matrix[0].size();
        int n = columns*matrix.size();
        
        int low = 0;
        int high = n-1;
        int mid;
        
        while(low<=high)
        {
            mid= low+ (high-low)/2;
            if(matrix [mid/columns][mid%columns] == target)
                return true;
            else if(matrix [mid / columns][mid % columns]>target)
                high = mid-1;
            else 
                low = mid+1;
        }
        return false;
    }
};
