class Solution {
public:
    int find(int a,vector<int>&par){
        if(a==par[a]) return a;
        return par[a]=find(par[a],par);
    }
    void unionn(int a,int b,vector<int>&par){
        a=find(a,par),b=find(b,par);
        par[a]=b;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res=0,cta=1,ctb=1;
        vector<int>para(n+1,0),parb(n+1,0);
        for(int i=0;i<n+1;i++){
            para[i]=i;
            parb[i]=i;
        }
        sort(edges.rbegin(),edges.rend());
        for(auto e:edges){
            if(e[0]==3){
                if(find(e[1],para)!=find(e[2],para)) {
                    unionn(e[1],e[2],para);
                    unionn(e[1],e[2],parb);
                    cta++;ctb++;
                }
                else res++;
            }
            else if(e[0]==2){
                if(find(e[1],parb)!=find(e[2],parb)) {
                    unionn(e[1],e[2],parb);
                    ctb++;
                }
                else res++;
            }
            else{
                if(find(e[1],para)!=find(e[2],para)) {
                    unionn(e[1],e[2],para);
                    cta++;
                }
                else res++;
            }
        }
        cout<<cta<<" "<<ctb<<endl;
        if(cta!=n or ctb!=n) return -1;
        return res;
    }
};