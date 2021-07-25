//https://leetcode.com/problems/push-dominoes/

class Solution {
public:

    string pushDominoes(string dominoes) {
        int left=0,right=1;
        while(left < dominoes.length()-1 && right < dominoes.length()){
            while(dominoes[right]=='.') right++;
            if(right>=dominoes.length() && dominoes[left]=='R'){
                for(int i=left;i<dominoes.length();i++) dominoes[i]='R';
                break;
            }
            if((dominoes[left]=='.' || dominoes[left]=='L') && dominoes[right]=='L'){
                for(int i=right;i>=left;i--) dominoes[i]='L';
                left=right+1;
                right=left+1;
            }
            else if(dominoes[left]=='.' && dominoes[right]=='R'){
                left=right;
                right=left+1;
            }
            else if(dominoes[left]=='L' && dominoes[right]=='R'){
                left=right;
                right=left+1;
            }
            else if(dominoes[left]=='R' && dominoes[right]=='R'){
                for(int i=right;i>=left;i--) dominoes[i]='R';
                left=right;
                right=left+1;
            }
            else if(dominoes[left]=='R' && dominoes[right]=='L'){
                for(int i=left,j=right;i<j;i++,j--){
                    dominoes[i]='R';
                    dominoes[j]='L';
                }
                left=right+1;
                right=left+1;
            }
        }
        return dominoes;
    }
};
