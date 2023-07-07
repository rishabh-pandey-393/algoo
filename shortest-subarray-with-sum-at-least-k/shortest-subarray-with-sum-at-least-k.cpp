class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>pq;
        pq.push({0,-1});
        long long sum=0,ans=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(pq.size() && sum-pq.top().first>=k){
                ans=min(ans,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans==INT_MAX?-1:ans;
    }
};