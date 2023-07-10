class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size(),xr=0;
        for(int i=0;i<n;i++) xr^=nums[i];
        int i=0;
        for(;i<31;i++) if(xr&(1<<i)) break;
        int a=0,b=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]&(1<<i)) a^=nums[j];
            else b^=nums[j];
        }
        return {a,b};
    }
};