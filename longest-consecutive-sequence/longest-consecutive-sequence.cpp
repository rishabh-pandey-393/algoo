class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(auto x:nums) s.insert(x);
        for(auto x:s){
            if(s.count(x-1)) continue;
            int ct=1;
            while(s.count(x+1)){
                ct++;
                x++;
            }
            ans=max(ans,ct);
        }
        return ans;
    }
};