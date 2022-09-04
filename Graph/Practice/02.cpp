#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v,wt;
};

int main()
{
    int n=6 , e=7;
    vector<node> edges={{0,1,5},{1,5,-3},{1,2,-2},{2,4,3},{3,2,6},{3,4,-2},{5,3,1}};

    vector<int>dis(n,10000);
    int src=0;
    dis[src]=0;

    for(int i=0; i<n; i++)
    {
        for(auto x:edges)
        {
            if(dis[x.u]+x.wt<dis[x.v])
                dis[x.v]= dis[x.u]+x.wt;
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }

}