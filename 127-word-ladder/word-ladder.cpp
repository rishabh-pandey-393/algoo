class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        set<string>st;
        for(int i=0;i<w.size();i++) st.insert(w[i]);
        if(!st.count(e)) return 0;
        queue<string>q;
        map<string,int>mp;
        q.push(b);
        mp[b]++;
        int ans=0;
        while(q.size()){
            int x=q.size();
            cout<<x<<endl;
            for(int i=0;i<x;i++){
                string s=q.front();
                if(s==e) return ans+1;
                q.pop();
                for(int i=0;i<s.size();i++){
                    char c=s[i];
                    for(int k=0;k<26;k++){
                        s[i]='a'+k;
                        if(st.count(s) && mp[s]==0) {
                            q.push(s);
                            mp[s]++;
                        }
                    }
                    s[i]=c;
                }
            }
            ans++;
        }
        return 0;
    }
};