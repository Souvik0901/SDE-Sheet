class Solution {
public:
    int romanToInt(string s) {
        int ans =0;
        unordered_map<int, int>mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        for(int i=0; i<s.size(); i++)
        {
            if(mp[s[i]]<mp[s[i+1]])
              ans-=mp[s[i]];
            else ans+=mp[s[i]];
        }
        return ans;

    }
};

Time Complexity: 0(N)
Space Complexity: 0(N)

    
    
    
    
    
....................................................................................................................................................................  
Integer to Roman:

class Solution {
public:
    string intToRoman(int num) {

       string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
       string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
       string hnds[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
       string tnds[]={"","M","MM","MMM"};

       return tnds[num/1000]+hnds[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];

    }
};

NOTE: nums %1000 = nums   ,    if nums <1000


    
    

