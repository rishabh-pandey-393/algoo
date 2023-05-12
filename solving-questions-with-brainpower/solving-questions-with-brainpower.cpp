class Solution {
public:
    long long f(int ind,vector<vector<int>>&q,vector<long long>&dp){
        if(ind>=q.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max(q[ind][0]+f(ind+q[ind][1]+1,q,dp),f(ind+1,q,dp));
    }
    long long mostPoints(vector<vector<int>>&q) {
        long long n=q.size();
        vector<long long>dp(n,-1);
        return f(0,q,dp);
    }
};