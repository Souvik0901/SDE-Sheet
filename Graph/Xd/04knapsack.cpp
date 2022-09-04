#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int val;
    int weight;
};

class solution
{
    public:

     static bool compare(struct Item a, struct Item b )
     {
         double r1= (double)a.val/(double)a.weight;
         double r2= (double)b.val/(double)b.weight;
          return r1>r2;
     }

     double knapsack(struct Item arr[], int maxw, int size)
     {
        sort(arr,arr+size,compare);
        double Cv=0;
        int Cw=0;

        for(int i=0; i<size; i++)
        {
            if(Cw+arr[i].weight<=maxw)
            {
                 Cw+=arr[i].weight;
                Cv+=arr[i].val;
                
               
            }

            else
            {
                int remain=(maxw-Cw);
                Cv+=((double) remain * (double)arr[i].val)/(double) arr[i].weight;
                break;
            }
        }
        return Cv;

     }
};

int main()
{
    Item arr[ ]={{60,20},{50,25},{20,5}};
     int size= sizeof(arr)/sizeof(arr[0]);
     int maxw=34;
     solution ob;
    cout<<ob.knapsack(arr,maxw,size);
}