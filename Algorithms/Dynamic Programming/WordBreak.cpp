//https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool>wordMap;
        for(auto x: wordDict) wordMap[x]=true;
        vector<vector<bool>>v1(s.length()+1,vector<bool>(s.length()+1,false));
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0 ; j <= s.length()-i; j++){
                if(wordMap[s.substr(j,i)]){
                    v1[j][j+i-1]=true;
                }
                else{
                    for(int k = j; k< i+j-1 ; k++){
                        if(v1[j][k]==true && v1[k+1][i+j-1]==true){
                            v1[j][i+j-1]=true;
                        }
                    }
                }
            }
        }
        return v1[0][s.length()-1];
    }
};
