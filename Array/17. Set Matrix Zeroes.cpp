

Brute Force Approach :
    Time Complexity : 0(NM)
    Space Complexity: 0(N)
      
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rowsize = matrix.size();
        int columnsize = matrix[0].size();
        vector<int>rowmarker(rowsize,1);
        vector<int>columnmarker(columnsize,1);

        for(int i=0; i<rowsize; i++)
        {
            for(int j=0; j<columnsize; j++)
            {
                if(matrix[i][j]==0){
                    rowmarker[i]=0;
                    columnmarker[j]=0;
                }
                
            }
        }


  for(int i=0; i<rowsize; i++)
        {
            for(int j=0; j<columnsize; j++)
            {
               if(rowmarker[i]==0 or columnmarker[j]==0)
               matrix[i][j]=0;
                
            }
        }
    }
};

Optimal Approach:

Time Complexity: 0(MN)
 Space Complexity: 0(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();     // row size
        int m = matrix[0].size();   // column size
        bool isRow0=false;
        bool isCol0= false;

        for(int i=0; i<n; i++)
        {
            if(matrix[i][0]==0)
            isRow0 =true;
        }

        for(int j=0; j<m; j++)
        {
            if(matrix[0][j]==0)
            isCol0 =true;
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        
        }

        for(int i=1; i<n; i++)
        {
            for(int j =1; j<m; j++)
            {
                if(matrix[i][0]==0 or matrix[0][j]==0)
                matrix[i][j]=0;

            }
        }

        for(int i=0; i<n; i++)
        {
            if(isRow0==true)
            matrix[i][0] =0;
        }

         for(int j=0; j<m; j++)
        {
            if(isCol0==true)
            matrix[0][j] =0;
        }
    }
};
