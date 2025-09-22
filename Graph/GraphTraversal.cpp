// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// DFS Traversal 
void dfshelper(vector<int>adj[], int node, vector<bool>&visited, vector<int>&ans){
    visited[node]= true;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!visited[it])
            dfshelper(adj, it, visited, ans);
    }
}

vector<int>dfs(vector<int>adj[], int n){
    vector<bool>visited(n, false);
    vector<int>ans;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfshelper(adj,i,visited, ans);
        }
    }
    return ans;
}


// Bfs Traversal
vector<int>bfs(vector<int>adj[], int n){
    vector<int>ans;
    vector<bool>visited(n, false);
    queue<int>q;
    q.push(1);
    visited[1]=true;

    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto it: adj[node]){
            if(!visited[it])
            {
                q.push(it);
                visited[it]=true;
            }
        }
    }
    return ans;
}


// Cycle Detection using bfs
bool checkCycleWithBfs(vector<int>adj[], int node, vector<bool>&visited, int size){
   queue<pair<int, int>>q;
   q.push({node, -1});

   while(!q.empty()){
     int top = q.front().first;
     int parent = q.front().second;
     visited[top] = true;
     q.pop();

     for(auto it: adj[top]){
         if(!visited[it]){
            visited[it] = true;
            q.push({it, top});
         }
         else if(it != parent) return true;
     }
   }
   return false;
}

bool isCycleDetect(vector<int>adj[], int n){
    vector<bool>visited(n, false);
    for(int i=1; i<n; i++){
        if(!visited[i])
            return checkCycleWithBfs(adj, i, visited, n);
       
    }
    return false;
}


// Cycle Detection Using DFS
bool checkCycleWithDFS(int node, int parent, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, node, adj, vis)) return true;
        }
        else if(it != parent) {
            return true;  // cycle found
        }
    }
    return false;
}

bool isCycleDetectDFS(int v, vector<int> adj[]) {
    vector<int> vis(v+1, 0);
    for(int i=1; i<=v; i++) {
        if(!vis[i]) {
            if(checkCycleWithDFS(i, -1, adj, vis)) return true;
        }
    }
    return false;
}



int main() {
  vector<int>adj[6];
  adj[1] = {2};
  adj[2]= {1,3,5};
  adj[3]= {2,4};
  adj[4]= {3,5};
  adj[5]= {2};
  
  vector<int>ans = dfs(adj, 6);
  cout<<"DFS Traversal : ";
  for(int i=1; i<6; i++){
      cout<<ans[i]<<" ";
  }
 
  cout<<"\nBFS Traversal : ";
  vector<int>bfsans = bfs(adj, 6);
  for(int i=0; i<5; i++){
      cout<<bfsans[i]<<" ";
  }
  

  cout<<"\nCycle Dtection using Bfs : ";
  bool result = isCycleDetect(adj, 6);
  cout<< result;

  cout<<"\nCycle Detection Using Dfs: ";
  cout<<isCycleDetectDFS(adj,6);
}
