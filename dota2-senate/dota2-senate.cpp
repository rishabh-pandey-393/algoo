class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dir,rad;
        for(int i=0;i<senate.length();i++) {
            if(senate[i]=='D') dir.push(i);
            else rad.push(i);
        }
        int s=senate.length();
        while(true){
            if(rad.empty()) return "Dire";
            if(dir.empty()) return "Radiant";
            int r=rad.front(),d=dir.front();
            rad.pop();
            dir.pop();
            if(r<d) rad.push(r+s);
            else dir.push(d+s);
        }
    }
};