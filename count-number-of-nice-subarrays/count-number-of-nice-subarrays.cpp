class Solution {
public:
    int f(vector<int>&nums,int k){
        int n=nums.size(),i=0,j=0,ct=0,ans=0;
        while(j<n){
            if(nums[j]%2==1) ct++;
            while(ct==k+1){
                if(nums[i]%2==1) ct--;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};