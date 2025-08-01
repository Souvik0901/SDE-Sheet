class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>>q;
        int fresh =0;  // count for fresh oranges
        int mins = 0;  // count minutes

        //Step 1 Add All initially rotten oranges to the queue
         for(int r =0; r<rows; r++){
            for(int c =0; c<cols; c++){
                if(grid[r][c] ==2)q.push({r,c}); 
                else if(grid[r][c]==1) fresh++;  //6
            }
         }
        
        // Directions UP , Down, Left , right
        vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

        //treavesal BFS
        while(!q.empty() && fresh >0){
            int size = q.size(); // Oranges that rot this minute
            mins++;   // time increment

            for(int i =0; i<size; i++){
              auto[r,c] = q.front(); 
              q.pop();

              for(auto[dr, dc]: directions){
                int nr = r+dr;
                int nc = c+dc;

                //check boundaries and if oranges are fresh
                if( nr>=0 && nr<rows && nc>=0 && nc< cols  && grid[nr][nc]== 1 ){
                    grid[nr][nc]= 2;
                    fresh--;
                    q.push({nr,nc});
                }
              }
            }
        }
     return  (fresh==0)?mins :-1;
    }
    
};
