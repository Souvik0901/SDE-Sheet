class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string s = strs[0];

        for(int i= 1; i<strs.size(); i++){
                int k2 =0;
                int k1 =0;


            // For Checking s[0] all characters continuously equals to strs[i] all elemnts.
            while(s.size()>k2 || strs.size()>k1){
                if(s[k2] == strs[i][k1]){
                    k2++;
                    k1++;
                }
                
                // If not then take the string s,  as a substring upto string matching.
                else{
                    s= strs[i].substr(0,k2);
                    break;
                }
            }
            
        }
        return s;
    }
};
