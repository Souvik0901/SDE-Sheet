class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) 
    {
        int i = 0;
        int j = nums.size()-1;
        long long sum =0;
        int c=0;
        while(i<j)
        {
          c= concat(nums[i],nums[j]);
           sum+= c;
            i++;
            j--;
            if(i==j)
             sum+=nums[i];
        }
        
        return sum;
    }
    
    long long concat(int n1, int n2)
    {
        string num1 = to_string(n1);
        string num2 = to_string(n2);
        num1 =num1+num2;
        
        long long p = stoi(num1);
        return p;
    }
};
