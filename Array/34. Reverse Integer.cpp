class Solution {
public:
    long int reverse(int x) {
     long int rem;
      long int res =0;
        bool neg = x<0;
        x = abs(x);
        
            while(x>0)
            {
            rem = x%10;
            //Checks if num is in required range or not to prevent overflow !
            if(res>INT_MAX/10 || res<INT_MIN/10)
                return 0;
            res= (res*10)+ rem;
            x/=10;
            }
        
        
        if(!neg)
            return res;
        else
        {
            res =res*-1;
            return res;
        }
    }
};




Space Complexity: 0(1);
