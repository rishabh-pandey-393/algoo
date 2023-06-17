class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),i=n-1,fl=0;
        string ans="",temp="";
        while(i>=0){
            if(s[i]==' '){
                ans+=temp;
                ans+=' ';
                temp="";
            }
            while(i>=0 && s[i]==' ') i--;
            if(i>=0 && s[i]!=' ') temp=s[i]+temp;
            i--;
        }
        ans=ans+temp;
        if (ans.back()==' ') ans.pop_back();
        if(ans[0]==' '){
            reverse(ans.begin(),ans.end());
            ans.pop_back();
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};