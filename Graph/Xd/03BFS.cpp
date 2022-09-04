#include<bits/stdc++.h>
using namespace std;



   vector<int> bfsofgraph(int n, vector<int>adj[])
   {
       vector<int> bfs;
       vector<int> vis(n+1,0);

       queue<int>q;
       q.push(6);
       vis[6]=1;

       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           bfs.push_back(node);

           for(auto it: adj[node])
           {
               if(!vis[it])
                {
                     q.push(it);
                     vis[it]=1;
                }
           }
       }
       return bfs;
   }



void addEdge(vector<int> adj[],int u, int v)
{
   adj[u].push_back(v);
   adj[v].push_back(u);
}


int main()
{
   vector<int> adj[8];
 
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 6);
  addEdge(adj, 2, 4);
  addEdge(adj, 6, 4);
  


  vector<int> ans=bfsofgraph(8,adj);
  for(int i=0; i<ans.size(); i++)
  {
      cout<< ans[i]<<" ";
  }
  return 0;
}