//https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        vector<int>v1(128,0);
        vector<string>v2(1e5,"");
        int maxx=0;
        string res="";
        for(char c:s) {
            v1[c]++;
            maxx=(maxx<v1[c])?v1[c]:maxx;
        }
        for(int i=0;i<128;i++)
            if(v1[i]>=1) v2[v1[i]]+=(char)i;

        for(int i=maxx;i>=0;i--){
            for(char c:v2[i]){
                for(int j=0;j<i;j++)
                   res+=c;
            }
        }
        return res;
    }
};
