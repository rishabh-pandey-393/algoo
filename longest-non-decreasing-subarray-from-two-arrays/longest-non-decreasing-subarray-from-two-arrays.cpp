class Solution {
public:
    int f(vector<int>&nums1,vector<int>&nums2,int ind,int fl,vector<vector<int>>&dp){
        if(ind==nums1.size()) return 0;
        if(fl==-1){
            return max({1+f(nums1,nums2,ind+1,0,dp),1+f(nums1,nums2,ind+1,1,dp),f(nums1,nums2,ind+1,-1,dp)});
        }
        if(dp[ind][fl]!=-1) return dp[ind][fl];
        int ans=0;
        if(fl==0){
            if(nums1[ind]>=nums1[ind-1]) ans=max(ans,1+f(nums1,nums2,ind+1,0,dp));
            if(nums2[ind]>=nums1[ind-1]) ans=max(ans,1+f(nums1,nums2,ind+1,1,dp));
        }
        else if(fl==1){
            if(nums1[ind]>=nums2[ind-1]) ans=max(ans,1+f(nums1,nums2,ind+1,0,dp));
            if(nums2[ind]>=nums2[ind-1]) ans=max(ans,1+f(nums1,nums2,ind+1,1,dp));
        }
        return dp[ind][fl]=ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(nums1,nums2,0,-1,dp);
    }
};