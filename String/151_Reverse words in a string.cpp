Optimized Approach: 

Time Complexity: 0(N);
Space Complexity: 0(1);

class Solution {
public:
    string reverseWords(string s)
    {
        string temp = "";
        string ans = "";
        int left = 0;
        int right = s.length()-1;

        while(left<=right)
        {
            char ch = s[left];
            if(ch !=' ')
            {
               temp += ch;
            }
            else if(ch ==' ') //For Every gap or space
            {
               if(ans=="") ans= temp;
               else ans = temp+" "+ans;

               temp ="";  // For every gap of words temp will start as blank
            }

            left++;
        }

        if(temp!="")  //  for last word added
        {
            if(ans!="") ans = temp+" "+ans;
            else ans = temp;
        }

        return ans;
        
    }
};


------------------------------------------------------------------------------
Approach 2:

Time Complexity: 0(N);
Space Complexity: 0(N);
class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string>st;
        
        for(int i=0; i<s.length(); i++)
        {
            string word ="";
            if(s[i]==' ') continue;
            while(s[i]!=' ' and i<s.length())
            {
                word+=s[i];
                i++;
            }
            st.push(word);
        }
        string ans ="";
        while(!st.empty())
        {
          ans+= st.top();
          st.pop();
          if(!st.empty()) ans+=" ";
        }
        return ans;
    }
};

------------------------------------------------------------------------------
//Approach 3: using substring
class Solution {
public:
    string reverseWords(string s) {
        int j =0;
        stack<string>st;
        for(int i=0; i<s.length(); i++){
            if(s[i]== ' '){
                if(i>j) st.push(s.substr(j, i - j));  
                j= i+1;
            }     
        }

        // push the last word
        if (j < s.length()) {
            st.push(s.substr(j, s.length() - j));
        }

        string ans = "";
        while(!st.empty()){
          ans+= st.top();
          st.pop();
          if(!st.empty()) ans+=" ";
        }
        return ans;
    }
};

