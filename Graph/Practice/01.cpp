#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

static bool compare(struct Item a, struct Item b )
{
    int r1= (double)(a.value/a.weight);
    int r2= (double)(b.value/b.weight);

    return r1>r2;

}
double knapsack(struct Item a[],int cap, int n)
{

   sort(a,a+n,compare);
   double CVal=0;
      int Cw=0;
   for(int i=0; i<n; i++)
   {
      
      if(Cw +a[i].weight<cap)
      { 
         CVal +=a[i].value;
         Cw+= a[i].weight;
      }

      else
      {
         int remain =(cap-Cw);
         CVal+= (double)((a[i].value * remain) /a[i].weight);
         break;
      }


   }
   
      return CVal;
}
int main()
{
   Item arr[]={{20,12},{34,8},{31,30}};
   int Capasity =23;
   int n= sizeof(arr)/sizeof(arr[0]);
   cout<<knapsack(arr,Capasity,n);

}
