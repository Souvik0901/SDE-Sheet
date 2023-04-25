class Solution {
public:
   
   void solve(int open, int close, int n, string current,vector<string>&res)
   {
       if(current.size()==2*n)
       {
           res.push_back(current);
           return;
       }


       if(open<n){
           solve(open+1,close,n,current+'(',res);
       }
       if(close<open){
           solve(open,close+1,n,current+')',res);
       }
   }


    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve(0,0,n,"",result);

        return result;
    }
};
