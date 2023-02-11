
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    
        int startrow=0;
        int startcol=0;
        int endrow = matrix.size()-1;
        int endcol = matrix[0].size()-1;
        vector<int> ans;

        while(startrow<=endrow && startcol<=endcol)
        {
            //from left to right
            for(int i=startcol;i<=endcol;++i){   
                ans.push_back(matrix[startrow][i]); 
            }
            startrow++;

            //from top to bottom
            for(int i=startrow;i<=endrow;++i){  
                ans.push_back(matrix[i][endcol]);
            }
            endcol--;
            
      

            //from right to left
            for(int i=endcol;i>=startcol;--i){ 
                ans.push_back(matrix[endrow][i]);
            }
            endrow--;

            //from bottom to top
            for(int i=endrow;i>=startrow;--i){ 
                ans.push_back(matrix[i][startcol]);
            }
            startcol++;

        }

        
        return ans;

    }
};


T.C : 0(N^2)
Space Complexity: 0(1)


