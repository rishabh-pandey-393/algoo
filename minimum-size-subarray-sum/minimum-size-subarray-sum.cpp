class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),ans=INT_MAX,s=-1,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i-s);
                sum-=nums[++s];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};