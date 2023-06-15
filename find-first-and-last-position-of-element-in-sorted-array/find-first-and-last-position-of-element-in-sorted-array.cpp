class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1,x,y;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target) hi=mid-1;
            else lo=mid+1;
        }
        x=lo;
        lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=target) lo=mid+1;
            else hi=mid-1;
        }
        if(x==n or hi==-1 or nums[x]!=target or nums[hi]!=target) return {-1,-1};
        return {x,hi};
    }
};