class Solution {
public:
    int f(vector<int>&nums,int bita,int bitb,int ind,vector<vector<vector<int>>>&dp,int s){
        if(ind==nums.size()) return 0;
        if(dp[ind][bita][bitb]!=-1) return dp[ind][bita][bitb];
        int ans=0;
        for(int i=0;i<s;i++){
            if(!(bita&(1<<i))) ans=max(ans,((i+1)&nums[ind])+f(nums,bita|(1<<i),bitb,ind+1,dp,s));
            else if(!(bitb&(1<<i))) ans=max(ans,((i+1)&nums[ind])+f(nums,bita,bitb|(1<<i),ind+1,dp,s));
        }
        return dp[ind][bita][bitb]=ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n=nums.size(),x=(1<<numSlots)+5;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(x,vector<int>(x,-1)));
        return f(nums,0,0,0,dp,numSlots);
    }
};