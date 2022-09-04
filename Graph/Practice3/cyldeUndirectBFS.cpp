#include<bits/stdc++.h>
using namespace std;

bool check(int src, int n, vector<int>&vis,vector<int>adj[])
{
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int par =q.front().second;
        q.pop();
        for(auto x: adj[node])
        {
            if(!vis[x])
            {
                vis[x]=1;
                q.push({x,node});
            }
            else if(vis[x]==1 and par!=node)
             return true;

        }

    }
    return false;
}

bool iscycle(int n, vector<int>adj[])
{
    vector<int>vis(n+1,0);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            if(check(i,n,vis,adj)==true)
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
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(iscycle(n,adj)==1)
     cout<<"Cycle Detect";
    else
     cout<<"Not Cycle";
}