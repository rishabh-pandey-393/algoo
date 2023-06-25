class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size(),ans=0,init=0,i=0;
        for(int j=0;j<n;j++){
            while(i<n && (init & nums[j])) init^=nums[i++];
            init|=nums[j];
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};