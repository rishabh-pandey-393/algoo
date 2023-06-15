class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        if(n==1) return nums[lo];
        if(nums[lo]!=nums[lo+1]) return nums[lo];
        if(nums[hi]!=nums[hi-1]) return nums[hi];
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if(mid%2==0){
                if(nums[mid]==nums[mid+1]) lo=mid+1;
                else hi=mid-1;
            }
            else {
                if(nums[mid]==nums[mid-1]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};