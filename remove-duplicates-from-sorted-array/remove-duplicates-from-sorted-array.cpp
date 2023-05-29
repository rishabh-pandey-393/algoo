class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),i=0,j=1;
        while(j<n){
            if(nums[j]!=nums[i]) swap(nums[j++],nums[++i]);
            else j++;
        }
        return i+1;
    }
};