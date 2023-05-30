class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),res=n,exc=0;
        for(int i=0;i<n;i++){
            res=res^i;
            exc=exc^nums[i];
        }
        return res^exc;
    }
};