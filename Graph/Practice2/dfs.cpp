

#include<bits/stdc++.h>
using namespace std;

void  dfs(int src, vector<int>adj[],vector<int>&vis,vector<int>&store)
{
     vis[src]=1;
     store.push_back(src);

     for(auto x:adj[src])
     {
        if(vis[x]==0)
        {
            vis[x]=1;
          dfs(x,adj,vis,store);
        }
     }   
}

vector<int> dfsofgraph(int v, vector<int>adj[])
{
    vector<int>vis(v+1,0);
    vector<int>store;
    for(int i=0; i<v; i++)
    {
        if(vis[i]==0)
         dfs(i,adj,vis,store);
    }
    return store;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
     vector<int>ans;
     ans=dfsofgraph(n,adj);
     for(int i=0; i<ans.size(); i++)
     {
        cout<<ans[i]<<" ";
     }
        
    

}