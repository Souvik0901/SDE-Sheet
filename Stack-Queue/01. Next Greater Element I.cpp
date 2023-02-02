class Solution {
public:
    map<int,int>mp;
    stack<int>st;
    void nxt(vector<int>&nums2)
    {
      for(int i=nums2.size()-1; i>=0; i--)
      {
        while(!st.empty() and st.top()<=nums2[i]) st.pop();
        int res = st.empty() ?-1 : st.top();
        mp[nums2[i]]=res;
        st.push(nums2[i]);
      }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
       vector<int>res;
       nxt(nums2);
       for(int i=0; i<nums1.size(); i++)
       {
         res.push_back(mp[nums1[i]]);
       }
       return res;
    }
};


Time Complexity: 0(N)
Space Complexity: 0(N)
