class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),sum=0,ans=0;
        unordered_map<int,int>mp;
        mp[sum]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1) sum+=nums[i];
            else sum-=1;
            if(mp.find(sum)!=mp.end()) ans=max(ans,i-mp[sum]);
            else mp[sum]=i;
        }
        return ans;
    }
};