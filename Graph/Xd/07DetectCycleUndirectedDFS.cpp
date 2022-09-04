#include<bits/stdc++.h>
using namespace std;

bool checkcycleDFS(int node, int par, vector<int>adj[],map<int,bool>vis)
{
    vis[node]=1;
    for(auto x: adj[node])
    {
        if(!vis[x])
        {
            if(checkcycleDFS(x,node,adj,vis))
                  return true;
        }
        else if(vis[x]==true and x!=par)
         return true;
    }
    return false;
}

bool iscycle(vector<int>adj[],int n)
{
    map<int,bool>vis;
    for(int i=1; i<n; i++)
    {
       if(!vis[i])
       {
          if(checkcycleDFS(i,-1,adj,vis))
             return true;
       }
    }
    return false;
}


int main()
{
    int n,m; //nodes & edges
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    if(iscycle(adj,n)==1)
       cout<<"Its A cycle";
    else
       cout<<"Not a cycle";
}