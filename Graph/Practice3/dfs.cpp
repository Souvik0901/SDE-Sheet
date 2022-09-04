#include<bits/stdc++.h>
using namespace std;

void bfsofgraph(int node, vector<int>&vis, vector<int>&ans, map<int,list<int>>adj)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto x: adj[node])
    {
       if(!vis[x])
       {
         bfsofgraph(x,vis,ans,adj);
       }
    }
}

vector<int>bfs(int n,map<int,list<int>>adj)
{
    vector<int>vis(n+1, 0);
    vector<int>ans;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            bfsofgraph(i,vis,ans,adj);
        }
    }
    return ans;
}


int main()
{
    int n,m;
    cin>>n>>m;
    map<int,list<int>>adj;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }


    vector<int>ans;
    ans=bfs(n,adj);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";

    }

}