#include<bits/stdc++.h>
using namespace std;

void FindTopo(vector<int>adj[],stack<int>&st,vector<int>&vis,int node)
{
      vis[node]=1;
      for(auto x: adj[node])
      {
          if(!vis[x])
          {
            FindTopo(adj,st,vis,x);
          }
      }
      st.push(node);
}



vector<int>toposort(vector<int>adj[], int n)
{
   stack<int>st;
   vector<int>vis(n,0);
   for(int i=1; i<=n; i++)
   {
        if(!vis[i])
        {
            FindTopo(adj,st,vis,i);
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
    int n,e;
    cin>>n>>e;
    vector<int>adj[n+1];
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans;
    ans= toposort(adj,n);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}