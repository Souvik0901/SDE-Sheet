#include<bits/stdc++.h>
using namespace std;


bool check(int node,int parent, vector<int>&vis, vector<int>adj[])
{
    vis[node]=1;
    for(auto x: adj[node])
    {
        if(!vis[x])
        {
            if(check(x,node,vis,adj))    // it means check()==1
            {
                return true;
            }
        }
        else if(vis[x]==1 and parent!=x)
        {
            return true;
        }
    }
  return false;
}



bool iscycle(int n,vector<int>adj[])
{
    vector<int>vis(n+1,0);
    int par =-1;
    for(int i=1; i<=n; i++)
    {
       if(!vis[i])
       {
          if(check(i,par,vis,adj)==1)
           return true;
       }
    }
    return false;
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
        adj[v].push_back(u);

    }

    if(iscycle(n,adj)==1)
     cout<<"Cycle Detected";
    else
      cout<<"it's Acyclic ";

}