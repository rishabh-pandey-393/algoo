class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int st=intervals[0][0],en=intervals[0][1];
        for(int i=1;i<n;i++){
            if(en>=intervals[i][0]) en=max(en,intervals[i][1]);
            else{
                ans.push_back({st,en});
                st=intervals[i][0];
                en=intervals[i][1];
            }
        }
        ans.push_back({st,en});
        return ans;
    }
};