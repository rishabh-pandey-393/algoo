class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>v(32,0);
        for(int i=0;i<n;i++)
            for(int j=31;j>=0;j--) if(nums[i]&(1<<j)) v[j]++;
            
        for(int i=31;i>=0;i--) if((v[i]%3)!=0) ans+=(1<<i);
        return ans;
    }
};