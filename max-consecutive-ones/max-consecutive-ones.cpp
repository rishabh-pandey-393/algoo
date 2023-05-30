class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),ans=0,x=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) x++;
            else {
                ans=max(ans,x);
                x=0;
            }
        }
        if(nums[n-1]==1) ans=max(ans,x);
        return ans;
    }
};