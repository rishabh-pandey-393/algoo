class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n+1,0);
        for(int i=0;i<=n-k;i++){
            if(i>0) temp[i]+=temp[i-1];
            if(temp[i]>nums[i]) return false;
            nums[i]-=temp[i];
            temp[i]+=nums[i];
            temp[i+k]-=nums[i];
        }
        for(int i=n-k+1;i<n;i++){
            temp[i]+=temp[i-1];
            if(temp[i]!=nums[i]) return false;
        }
        return true;
    }
};