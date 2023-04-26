class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long sum=0,n=nums.size(),ans=0;
        map<long long,long long>mp;
        mp[sum]=1;
        for(int i=0;i<n;i++){
            sum^=nums[i];
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};