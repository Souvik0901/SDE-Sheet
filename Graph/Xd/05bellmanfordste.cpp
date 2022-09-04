
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int w;
  
};

int main()
{
   int n=6,m=7;

   vector< node >edges={{0,1,5},{1,5,-3},{1,2,-2},{2,4,3},{3,2,6},{3,4,-2},{5,3,1}};

    vector<int >dist(n,100000);
    int src=0;
    dist[src]=0;

    ///Main Code Here
    for(int i=0; i<n; i++)
    {
        for(auto x:edges)
        {
            if(dist[x.u]+x.w<dist[x.v])
               dist[x.v]= dist[x.u]+x.w;
        }
    }

    //Recheck There is cycle or not
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