
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int v, vector<int>adj[])
{
   vector<int>visited(v+1,0);
   vector<int>ans;
    queue<int>q;
   q.push(0);
   visited[0]=1;

   while(!q.empty())
   {
      int node = q.front();
      q.pop();
       ans.push_back(node);

       for(auto x:adj[node])
       {
          if(!visited[x])
          {
             visited[x]=1;
            q.push(x);
          }
       }
   }
   return ans;
}


int main()
{
   int v,e;
   cin>>v>>e;
   vector<int>adj[v+1];
   for(int i=0; i<e; i++)
   {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
    vector<int> ans;
    ans=bfs(v,adj);
    for(int i=0;i<ans.size(); i++)cout<<ans[i]<<" ";
}