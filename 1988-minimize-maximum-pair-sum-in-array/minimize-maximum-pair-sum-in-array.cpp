class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1,i=0,ans=INT_MIN;
        while(i<j){
            ans=max(ans,nums[i++]+nums[j--]);
        }
        return ans;
    }
};