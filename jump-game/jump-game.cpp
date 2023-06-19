class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),i=0,x=0;
        while(i<n && i<=x) x=max(x,i+nums[i++]);
        if(i==n) return true;
        return false;
    }
};