#include<bits/stdc++.h>
using namespace std;

int adj[8][8]= {{0,1,1,1,0,1,0,0},
	            {0,0,0,1,0,0,0,0},
	            {0,0,0,1,1,0,0,0},
	            {0,0,0,0,1,1,0,0},
	            {1,0,0,0,0,1,0,0},
	            {0,0,0,0,0,0,0,0},
	            {0,1,0,0,0,0,0,1},
                {0,0,0,1,0,0,0,0}} ;



void dfs(int vis[],int u, int n)
{
    if(vis[u]==0)
     {
            cout<<u<<" ";
            vis[u]=1;
        for(int v=0; v<n; v++)
        {
            if(adj[u][v]==1  and vis[v]==0)
                dfs(vis, v,n);
        }
     }

}


int main()
{
    int static vis[8]={0};
   for(int i=0; i<8; i++)
   {
      if(vis[i]==0)
      {
        dfs(vis,0,8);
      }
   }
    

}