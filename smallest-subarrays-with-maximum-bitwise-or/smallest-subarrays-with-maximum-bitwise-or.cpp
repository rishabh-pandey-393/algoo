class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>bit(32,-1),ans(n);
        for(int i=n-1;i>=0;i--){
            int mx=i;
            for(int j=0;j<32;j++) {
                if(nums[i]&(1<<j)) bit[j]=i;
                mx=max(mx,bit[j]);
            }
            ans[i]=mx-i+1;
        }
        return ans;
    }
};