class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long n=nums.size(),ans=0;;
        map<long long,long long>mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(mp[nums[i]]<mp[nums[i-1]]) ans+=1ll*(n-i);
        }
        return n+ans;
    }
};