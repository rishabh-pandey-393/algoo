class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(),s=intervals[0][0],e=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(e<intervals[i][0]){
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else e=max(e,intervals[i][1]);
        }
        ans.push_back({s,e});
        return ans;
    }
};