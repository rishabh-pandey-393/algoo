class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            string ss=s.substr(1,s.size()-1)+s[0];
            if(ss==goal) return true;
            s=ss;
        }
        return false;
    }
};