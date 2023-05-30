class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int mxs=nums[0],crs=nums[0];
        for(int i=1;i<n;i++){
            if(crs<0) crs=0;
            crs+=nums[i];
            mxs=max(mxs,crs);
        }
        mxs=max(mxs,crs);
        return mxs;
    }
};