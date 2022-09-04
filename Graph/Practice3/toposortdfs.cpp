
#include<bits/stdc++.h>
using namespace std;

void Findtopo(int node, stack<int>&st, vector<int>&vis,vector<int>adj[] )
{
    vis[node]=1;
    for(auto x:adj[node])
    {
        if(!vis[x])
        {
            Findtopo(x,st,vis,adj);
        }
    }
    st.push(node);
}

vector<int>topo(int n, vector<int>adj[])
{
    stack<int>st;
    vector<int>vis(n+1,0);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            Findtopo(i,st,vis,adj);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
       ans.push_back(st.top());
       st.pop();
    }
    return ans;
    
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
    vector<int>ans;
    ans=topo(n,adj);
    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
} 

