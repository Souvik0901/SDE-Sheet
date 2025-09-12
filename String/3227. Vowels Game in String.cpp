class Solution {
public:
    bool doesAliceWin(string s) {
        for(int i=0; i<s.length(); i++){
            if(isvowels(s[i]))
              return true;
        }
        return false;
    }
    bool isvowels(char ch){
        if(ch== 'a'|| ch =='e' || ch=='i' || ch == 'o' || ch =='u')
          return true;

       return false;
    }
};



______________________________________________________________________
