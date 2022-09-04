#include<bits/stdc++.h>
using namespace std;


bool check(int node,int v, vector<int>adj[],vector<int>&vis)
{
    vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,-1});
     
    while(!q.empty())
    {
        int p=q.front().first;
        int par=q.front().second;
        q.pop();
        

        for(auto x: adj[p])
        {
            if(!vis[x])
            {
                q.push({x,p});
                vis[x]=1;
            }
            else if(vis[x]==1 and par!=x)
            {
                return true;
            }
        }
    }
    return false;
}


bool iscycle(int n, vector<int>adj[])
{
    vector<int>vis(n+1,0);

    for(int i=0; i<=n; i++)
    {
        if(vis[i]==0){
        if(check(i,n,adj,vis))
          return true;
        }
    
    }
    return false;
   
}


int main()
{
    int n,m;
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
       cout<<"it's Acyclic";
    
}