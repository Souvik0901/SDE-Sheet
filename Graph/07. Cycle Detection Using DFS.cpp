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

_____________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, node, adj, vis)) return true;
        }
        else if(it != parent) {
            return true;  // cycle found
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    vector<int> vis(v+1, 0);
    for(int i=1; i<=v; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int v = 5;
    vector<int> adj[v+1];

    // Graph with cycle
    adj[1] = {2};
    adj[2] = {1, 3, 5};
    adj[3] = {2, 4};
    adj[4] = {3, 5};
    adj[5] = {4, 2};

    if(isCycle(v, adj))
        cout << "Cycle Detected\n";
    else
        cout << "Cycle Not Detected\n";
}

_________________________________________________________________________________________________
