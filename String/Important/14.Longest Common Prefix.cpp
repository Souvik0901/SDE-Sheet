class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0]; 
       
        for(int i=1; i<strs.size(); i++){
            int k=0;
            int k1=0;
            while(s.size()>k1 || strs[i].length()>k){
                if(strs[i][k]== s[k1]){
                    k++;
                    k1++;
                }else{
                    s = strs[i].substr(0,k);
                    break;
                }
            }
        }
        return s;
    }
};
