>>  Approah 1: Brute Force

    Time Complexity: 0(N^2)
    Space Complexity: 0(1)
      
>> Code:

#include<bits/stdc++.h>
using namespace std;

int MaxProfit(vector<int>&prices)
{
    int maxpro =0;
    for(int i=0; i<prices.size();i++)
    {
        for(int j=i+1; j<prices.size();j++)
        {
            if(prices[j]>prices[i])
              maxpro= max(prices[j]-prices[i], maxpro);
        }
    }
    return maxpro;
}

int main()
{
    vector<int>prices={7,5,4,5,6,8};
    int ans = MaxProfit(prices);
    cout<<ans;
}
------------------------------------------------------------------------------------------------------------------------------------

>> Optimal Solution 
       Time Complexity: 0(N)
       Space Complexity: 0(1)
 
>> Code: 

#include<bits/stdc++.h>
using namespace std;

int MaxProfit(vector<int>&prices)
{
    int maxpro=0;
    int minprice = INT_MAX;
    for(int i=0; i<prices.size(); i++)
    {
        minprice = min(minprice,prices[i]);
        maxpro = max(maxpro,prices[i]-minprice);
    }
    return maxpro;
}

int main()
{
    vector<int>prices={7,5,4,9};
    int ans = MaxProfit(prices);
    cout<<ans;
}
