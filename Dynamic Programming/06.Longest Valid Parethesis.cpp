int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  // Base index
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxLength = max(maxLength, i - st.top());
            }
        }
    }
    return maxLength;
}


//Time Complexity: 0(N)
//Space Complexity: 0(N)


_______________________________________________________________________
int longestValidParentheses(string s) {
    int left =0;
    int right =0;
    int maxLen =0;

    //forward traversal
    for(auto it: s){
        if(it == ')')right++;
        else left++;

        if(left == right) maxLen = max(maxLen, 2*right);
        if(left <right) left =right =0;
    }
    // Reset before backward traversal
    left = right = 0;

    //backard traversal
    for(int i = s.length()-1; i>=0; i--){
        if(s[i]=='(')left++;
        else right++;

        if(left == right) maxLen = max(maxLen, 2*left);
        if(left > right) left=right =0;
    }

    return maxLen;
}

//Time Complexity: 0(N)
//Space Complexity: 0(1)



_____________________________________________________________________
