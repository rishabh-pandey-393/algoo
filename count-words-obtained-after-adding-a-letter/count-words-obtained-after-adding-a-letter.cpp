class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<s.size();i++){
            int mask=0;
            for(int j=0;j<s[i].size();j++) mask^=(1<<(s[i][j]-'a'));
            mp[mask]++;
        }
        for(int i=0;i<t.size();i++){
            int mask=0;
            for(int j=0;j<t[i].size();j++) mask^=(1<<(t[i][j]-'a'));
            for(int j=0;j<26;j++){
                if((mask&(1<<j))==0) continue;
                int x=mask^(1<<j);
                if(mp[x]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};