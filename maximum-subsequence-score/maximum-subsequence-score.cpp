class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=INT_MIN,n=nums1.size(),sum=0;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++) vp.push_back({nums2[i],nums1[i]});
        sort(vp.rbegin(),vp.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k-1;i++) {
            pq.push(vp[i].second);
            sum+=vp[i].second;
        }
        for(int i=k-1;i<n;i++){
            pq.push(vp[i].second);
            sum+=vp[i].second;
            ans=max(ans,sum*vp[i].first);
            sum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};