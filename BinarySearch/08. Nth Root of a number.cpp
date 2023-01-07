#include<bits/stdc++.h>
using namespace std;
double getmultiply(double number, int n)
{
   double ans=1.0;
   for(int i=0; i<n; i++)
   {
      ans= ans*number;
   }
   return ans;
}

void getNthRoot(int n, int m)
{
    double low=1;
    double high=m;
    double epsilon = 1e-7;

    while((high-low)>epsilon)
    {
        double mid = low+(high-low)/2.0;
        if(getmultiply(mid,n)<m) low =mid;
        else high = mid;
    }

    cout<<low<<endl;
}


int main()
{
    int n=3;
    int m=27;
    getNthRoot(n,m);
    return 0;
}

