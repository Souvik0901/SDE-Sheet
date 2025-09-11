class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0;
        int total_cost = 0;
        int remaining_gas = 0;
        int start_point = 0;

        for(int i=0; i<n; i++){
            total_gas+= gas[i];
            total_cost+= cost[i];
            remaining_gas+= gas[i]-cost[i];

            if(remaining_gas<0){
              start_point = i+1;
              remaining_gas = 0;
            }
        }
     return (total_cost>total_gas)?-1: start_point;
    }
};


----------------------------------------------------------------------
