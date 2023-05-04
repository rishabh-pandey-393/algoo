class Solution {
public:
    int f(string &s1,string &s2,int m,int n,vector<vector<int>>&dp){
        if(m<0 or n<0){
            int res=0;
            for(int i=m;i>=0;i--) res+=s1[i];
            for(int i=n;i>=0;i--) res+=s2[i];
            return res;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m]==s2[n]) return dp[m][n]=f(s1,s2,m-1,n-1,dp);
        return dp[m][n]=min(s1[m]+f(s1,s2,m-1,n,dp),s2[n]+f(s1,s2,m,n-1,dp));
    }

    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(s1,s2,m-1,n-1,dp);
    }
};