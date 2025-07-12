class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long sum =0;
        for (int i=0; i<nums.size()/2; i++){
            sum+= concatenate(nums[i], nums[n-1-i]);
        }

        if(n %2 == 1){
            sum+=nums[n/2];
        }
        return sum;
    }

    long long concatenate(long long a, long long b){
        long long mul = 10;
        for (long long t = b; t >= 10; t /= 10) mul *= 10;       // Logic for concatenate two number   
        return a * mul + b;
    }
};
