class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.size(),mask=0;
        vector<int>mp(n);
        vector<bool>ans;
        for(int i=0;i<n;i++){
            mask^=(1<<(s[i]-'a'));
            mp[i]=mask;
        }
        for(auto q: queries){
            int l=q[0],r=q[1],k=q[2];
            int ll=0,rr=mp[r],ct=0;
            if(l!=0) ll=mp[l-1];
            int x=ll^rr;
            while(x){
                if(x%2) ct++;
                x/=2;
            }
            ans.push_back(k>=ct/2);
        }
        return ans;
    }
};