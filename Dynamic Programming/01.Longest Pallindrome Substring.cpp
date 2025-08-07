class Solution {
public:
    string longestPalindrome(string str) {
        if(str.length()<=1)return str;
        int max_len = 1;
        string max_str= str.substr(0, 1);

        for(int i=0; i<str.length(); i++){
            for(int j= max_len+i; j<=str.length(); j++ ){
                if( j-i > max_len && isPallindrome(str.substr(i,j-i))){
                    max_len = j-i;
                    max_str = str.substr(i, max_len);
                }
            }
        }
        return max_str;
    }

    bool isPallindrome(string str){
        int left = 0;
        int right = str.length()-1;
        while(left<right){
            if(str[left]!=str[right])return false;
            left++;
            right--;
        }
        return true;
    }
};

Time-Complexity: 0(N^3)
------------------------------------------------------------------------------------------------

