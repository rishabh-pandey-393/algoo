class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i=n-1;
        while(i>0){
            if(nums[i-1]<nums[i]) break;
            i--;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        i--;
        int j=n-1;
        while(j>0){
            if(nums[j]>nums[i]){
                swap(nums[j],nums[i]);
                break;
            }
            j--;
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};