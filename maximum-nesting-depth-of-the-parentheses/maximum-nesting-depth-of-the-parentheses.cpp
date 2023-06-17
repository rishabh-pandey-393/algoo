class Solution {
public:
    int maxDepth(string s) {
        int ans=0,n=s.size(),ct=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') ct++;
            else if(s[i]==')') ct--;
            ans=max(ans,ct);
        }
        return ans;
    }
};