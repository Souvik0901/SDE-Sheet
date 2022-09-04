
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int w;
    node(int first, int second, int wt)
    {
        u=first;
        v=second;
        w=wt;
    }
};

int main()
{
   int n,m;
   cin>>n>>m;

   vector<node>edges;
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    int src;
    cin>>src;
    vector<int>dist(n,10000000);
    dist[src]=0;

    for(int i=0; i<n; i++)
    {
        for(auto x:edges)
        {
            if(dist[x.u]+x.w<dist[x.v])
               dist[x.v]= dist[x.u]+x.w;
        }
    }

    int count=0;
    for(auto it :edges)
    {
        if(dist[it.u]+it.w <dist[it.v])
          cout<<"Negative Cycle";
    }

    if(!count)
    {
        for(int i=0; i<n; i++)
        {
            cout<<i<<" "<<dist[i]<<endl;
        }
    }

}