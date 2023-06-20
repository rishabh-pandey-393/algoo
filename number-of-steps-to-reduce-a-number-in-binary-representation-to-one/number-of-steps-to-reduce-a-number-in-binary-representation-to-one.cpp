class Solution {
public:
    int numSteps(string s) {
        int i=s.size()-1,ans=0;
        while(s!="1"){
            if(s.back()=='0') {
                s.pop_back();
                ans++;
            }
            else{
                while(s.size() && s.back()=='1') {
                    s.pop_back();
                    ans++;
                }
                if(s.size()==0) return ans+1; 
                s.back()='1';
                ans++;
            }
        }
        return ans;
    }
};