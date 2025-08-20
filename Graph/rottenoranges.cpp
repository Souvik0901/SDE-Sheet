#include<bits/stdc++.h>
using namespace std;


//function for rotten oranges
int rottenOranges(vector<vector<int>>&grid){
   int mins =0;
   int fresh =0;
   int rows = grid.size();
   int cols = grid[0].size();
   queue<pair<int, int>>q;
  
  //initially 
   for(int r=0; r<rows; r++){
    for(int c=0; c<cols; c++){
        if(grid[r][c]==2)
          q.push({r,c});
        else if(grid[r][c]==1)fresh++;
    }
   }

   //directions
   vector<pair<int,int>>dir ={{-1,0},{0,-1},{1,0},{0,1}};

   //bfs 
   while(!q.empty() and fresh>0){
    mins++;
      for(int i=0; i<q.size(); i++){
        auto[r,c]= q.front();
        q.pop();
        for(auto[dr, dc]: dir){
            int nr = r+dr;
            int nc = c+dc;
           if(nr>=0 and nr<rows and nc>=0 and nc<cols and grid[nr][nc] ==1){
             grid[nr][nc]=2;
             fresh--;
             q.push({nr,nc});
           }
        }
      }

   }
   return fresh==0? mins:-1;
}



int main(){
    vector<vector<int>>grid= {{2,1,1},{1,1,0},{0,1,1}};
    int result= rottenOranges(grid);
    cout<<"Roten Oranges time taken: ";
    cout<<result<<endl;
}
