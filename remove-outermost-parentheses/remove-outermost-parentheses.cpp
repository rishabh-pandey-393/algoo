class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size(),ct=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(ct!=0) ans+=s[i];
                ct++; 
            }
            else {
                ct--;
                if(ct!=0) ans+=s[i];
            }
        }
        return ans;
    }
};