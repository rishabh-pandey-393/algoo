class Solution {
public:
    int ff(int l,int mid,int r,vector<int>&nums){
        vector<int>left(mid-l+1);
        vector<int>right(r-mid);
        int x=l,y=mid+1,k=l,ans=0,j=mid+1;
        for(int i=l;i<=mid;i++){
            while(j<=r && nums[i]>2ll*nums[j]) j++;
            ans+=(j-mid-1);
        }
        for(int i=0;i<mid-l+1;i++) left[i]=nums[x++];
        for(int i=0;i<r-mid;i++) right[i]=nums[y++];
        x=0,y=0;
        while(x<mid-l+1 && y<r-mid){
            if(left[x]<=right[y]) nums[k++]=left[x++];
            else nums[k++]=right[y++];
        }
        while(x<mid-l+1) nums[k++]=left[x++];
        while(y<r-mid) nums[k++]=right[y++];
        return ans;
    }
    int f(int l,int r,vector<int>&nums){
        if(l>=r) return 0;
        int mid=l+(r-l)/2;
        int left=f(l,mid,nums);
        int right=f(mid+1,r,nums);
        int lr=ff(l,mid,r,nums);
        return left+right+lr;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return f(0,n-1,nums);
    }
};