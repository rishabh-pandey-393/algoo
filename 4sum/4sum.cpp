class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=(long)nums[i]+(long)nums[j]+(long)nums[l]+(long)nums[r];
                    if(sum<target) l++;
                    else if(sum>target) r--;
                    else {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<n-1 && nums[l]==nums[l+1]) l++;
                        while(r>0 && nums[r]==nums[r-1]) r--;
                        l++;r--;
                    }
                }
            }
        }
        return ans;
    }
};