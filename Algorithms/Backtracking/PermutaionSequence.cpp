//https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fa(10);
        vector<int>visited(10,0);
        string s="";
        fa[0]=1;fa[1]=1;
        for(int i=2;i<=n;i++)
            fa[i]=i*fa[i-1];
        int count=n,j=k;
        while(count>0){
            int grp=fa[count]/count;
            int t=ceil(j*1.0/grp);
            int c=t;
            for(int m=1;m<=n;m++){
                if(!visited[m]){
                    c--;
                }
                if(!c){
                    visited[m]=1;
                    s+=to_string(m);
                    break;
                }
            }
            j=j-(t-1)*grp;
            count--;
        }
        return s;

    }
};
