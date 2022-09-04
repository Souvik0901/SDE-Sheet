#include<bits/stdc++.h>
using namespace std;


void bfsofgraph(int p ,vector<int>adj[],vector<bool>&vis, vector<int>&store)
{
    vis[p]=true;
    queue<int>q;
    q.push(p);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        store.push_back(node);
        for(auto x: adj[node])
        {
            if(!vis[x])
            {
                vis[x]=true;
                q.push(x); 
            }
        }
    }
}


vector<int>BFS(int n, vector<int>adj[])
{
    vector<bool>vis(n+1,false);
    vector<int>store;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==false)
        {
          bfsofgraph(i,adj,vis,store);
        }
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
        adj[v].push_back(u);
    }

    vector<int>ans;
    ans=BFS(n,adj);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}