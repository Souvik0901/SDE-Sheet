
Time Complexity: 0(N)
Space Complexity: 0(1)
  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int sell =0;
        int buy =0;
        int profit =0;
        for(int i=0; i<prices.size()-1; i++)
        {
            while(i<prices.size()-1  and prices[i]>= prices[i+1])
            {
                i++;
            }
            buy = prices[i];
            while(i<prices.size()-1 and prices[i]<prices[i+1])
            {
                i++;
            }
            sell = prices[i];
            profit+= sell-buy;
        }
        return profit;
    }
};




Time Complexity: 0(N)
Space Complexity: 0(1)
  
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i=0; i<prices.size()-1; i++)
        {
           if(prices[i]<prices[i+1])
           profit+= prices[i+1]-prices[i];
        }
        return profit;
    }
};
