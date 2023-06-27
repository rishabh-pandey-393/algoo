class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),lo=0,hi=nums[n-1]-nums[0];
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int i=0,j=0,ct=0;
            while(j<n){
                while(nums[j]-nums[i]>mid) i++;
                ct+=(j-i);
                j++;
            }
            if(ct>=k) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};