class Solution {
public:

    vector<string>ans;
    map<int,string>mp;
    vector<string> letterCombinations(string digits) 
    {
        if(digits == "") return ans;
        mp[2]= "abc";
        mp[3]= "def";
        mp[4]= "ghi";
        mp[5]= "jkl";
        mp[6]= "mno";
        mp[7]=  "pqrs";
        mp[8]= "tuv";
        mp[9]= "wxyz";
        string temp;
        backtrack(digits,0,temp);
        return ans;
    }

    void backtrack(string&dig, int start, string&temp)
    {
        if(start == dig.size()) ans.push_back(temp);

        for(auto it: mp[dig[start]-'0'])
        {
            temp.push_back(it);
            backtrack(dig,start+1,temp);
            temp.pop_back();
        }
    }
};


Time Complexity: 0(4^N)
S.C: 0(4^N);
