#include<bits/stdc++.h>
using namespace std;

// function for bfs traversal
vector<int>bfs(int n,vector<int>adj[]){
      vector<int>ans;   //for storing answer of breadth first search 
      vector<int>vis(n+1,0); //checking all nodes individually visited or not
      queue<int>q;         //used to search first in first out way

      q.push(0);      //need to push first index from where to start
      vis[0]=1;       // marking the first node as visited

      while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node); // each time fist in value of queue would be enter 
        
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
      }
      return ans;
}


//function for rotten oranges
// int rottenOranges(vector<vector<int>>&grid){
//    int mins =0;
//    int fresh =0;
//    int rows = grid.size();
//    int cols = grid[0].size();
//    queue<pair<int, int>>q;
  
//   //initially 
//    for(int r=0; r<rows; r++){
//     for(int c=0; c<cols; c++){
//         if(grid[r][c]==2)
//           q.push({r,c});
//         else if(grid[r][c]==1)fresh++;
//     }
//    }

//    //directions
//    vector<pair<int,int>>dir ={{-1,0},{0,-1},{1,0},{0,1}};

//    //bfs 
//    while(!q.empty() and fresh>0){
//     mins++;
//       for(int i=0; i<q.size(); i++){
//         auto[r,c]= q.front();
//         q.pop();
//         for(auto[dr, dc]: dir){
//             int nr = r+dr;
//             int nc = c+dc;
//            if(nr>=0 and nr<rows and nc>=0 and nc<cols and grid[nr][nc] ==1){
//              grid[nr][nc]=2;
//              fresh--;
//              q.push({nr,nc});
//            }
//         }
//       }

//    }
//    return fresh==0? mins:-1;
// }

//recursive dfs helper
void dfshelper(int node, vector<int>adj[], vector<int>&ans, vector<bool>&visited){
   visited[node]=true;
   ans.push_back(node);

   for(auto neighbor: adj[node]){
    if(!visited[neighbor]){
        dfshelper(neighbor, adj, ans, visited);
    }
   }
}

//function for dfs traversal
vector<int>dfs(int n, vector<int>adj[]){
   vector<int> ans;
   vector<bool>visited(n, false);
   for(int i=0; i<n; i++){
     if(!visited[i])dfshelper(i, adj, ans, visited);
   }
   return ans;
}


void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}



int main(){
    vector<int>adj[9];
    addEdge(adj,0,1);
    addEdge(adj,2,4);
    addEdge(adj,1,7);
    addEdge(adj,4,6);
    addEdge(adj,4,1);
    addEdge(adj,7,5);
    addEdge(adj,0,3);
    addEdge(adj,3,8);

    //bfs output return
    vector<int>ans = bfs(8, adj);
    for(int i =0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    // vector<vector<int>>grid= {{2,1,1},{1,1,0},{0,1,1}};
    // int result= rottenOranges(grid);
    // cout<<"Roten Oranges time taken: ";
    // cout<<result<<endl;


    //dfs output return
    vector<int>dfsresult = dfs(8,adj);
    for(int i =0; i<ans.size(); i++){
        cout<<dfsresult[i]<<" ";
    }
}


