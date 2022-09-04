
#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<int>adj[],int n)
{
    vector<int> visited(n+1,false);
    vector<int>store;
    
    queue<int>q;
    // for(int i =0; i<n ; i++)
    // {
    //     if(!visited[i])
    //     {
             q.push(0);
             visited[0]=true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                store.push_back(node);

                for(auto x: adj[node])
                {
                    if(!visited[x]) 
                      {
                        q.push(x);
                       visited[x]=true;
                      }
                }

            }
    //     }
    // }
  return store;

}

void addedges(vector<int>adj[], int u,int v)
{
   adj[u].push_back(v);
   adj[v].push_back(u);
}
int main()
{
    vector<int>adj[7];

    addedges(adj,0,1);
    addedges(adj,1,2);
    addedges(adj,1,3);
    addedges(adj,1,4);
    addedges(adj,4,5);
    addedges(adj,2,4);
    addedges(adj,3,4);
    addedges(adj,6,3);
   
    int n =7, e= 8;
   vector<int>ans= BFS(adj,n);

   for(int i =0; i<ans.size(); i++)
   {
     cout<<(char)(ans[i]+'A')<<" ";
   }


}