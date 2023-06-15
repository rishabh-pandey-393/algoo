class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev]) return nums[mid];
            else if(nums[n-1]<nums[mid]) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};