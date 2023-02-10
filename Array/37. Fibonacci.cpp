class Solution {
public:
    int fib(int n) 
    {
        if(n==0  or n==1) return n;
        if(n==2)return 1;
        int l = n-1;
        int r= n-2;

        return fib(l)+fib(r);
    }
};
