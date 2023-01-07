#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;

};

int main()
{
    int n =6, m=7;
  
    node arr[m]={{0,1,5},{1,5,-3},{1,2,-2},{2,4,3},{3,2,6},{3,4,-2},{5,3,1}};
    int  src=0;
    int dist[n]={100000};
    dist[src]=0;
    
    for(int i=1; i<=n-1; i++)
    {
        for(int j=0; j<n; j++)  // ata te ki korbo???? akane kichu gorbor korecchi ans kore patha......
        {
        if((dist[arr[i].u]+arr[i].wt)< dist[arr[i].v])
           dist[arr[i].v]= dist[arr[i].u]+arr[i].wt;
        }
    }

    for(int i=0; i<n; i++)
    {
       cout<<i<<" -> "<<dist[i]<<endl;
    }

    

}