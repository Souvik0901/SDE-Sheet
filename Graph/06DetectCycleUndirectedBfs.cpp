
#include<bits/stdc++.h>
using namespace std;

bool checkforcycle(int s, int v, vector<int>adj[],vector<int>&vis)
{
    vis[s]=0;
    queue<pair<int,int>>q;
    q.push({s,-1});

    while(!q.empty())
    {
        int node=q.front().first;
        int par =q.front().second;
        q.pop();

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if(par!=it)
             return true;
        }
    }
    return false;
}
bool iscycle(int v, vector<int>adj[])
{
    vector<int>vis(v+1,0);
    for(int i=1; i<=v; i++)
    {
        if(!vis[i])
        {
           if(checkforcycle(i,v,adj,vis));
            return true;
        }
    }

}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1];
    for(int i=0; i<e; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(iscycle(v,adj)==1)
       cout<<"Cycle Detected";
    else
       cout<<"Cycle Not Detected";

}