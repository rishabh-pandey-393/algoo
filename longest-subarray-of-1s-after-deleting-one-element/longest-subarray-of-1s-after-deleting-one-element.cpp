class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,ct=0,ans=0;
        while(i<n && j<n){
            if(nums[j]==1){
                ans=max(ans,j-i);
            }
            else {
                ct++;
                while(ct>1){
                    if(nums[i]==0) ct--;
                    i++;
                }
                ans=max(ans,j-i);
            }
            j++;
        }
        return ans;
    }
};