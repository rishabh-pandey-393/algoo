class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        long long sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>0) ans++;
        }
        return ans;
    }
};