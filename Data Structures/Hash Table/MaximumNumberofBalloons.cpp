//https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp = {{'b',1},{'a',1},{'l',2},{'o',2},{'n',1}};
        unordered_map<char,int>mp2;
        for(char ch : text) mp2[ch]++;
        string input = "balloon";
        int maxBalloons = 0;
        maxBalloons = (mp2['b']/mp['b']);
        for(char ch: input){
            if((mp2[ch]/mp[ch]) < maxBalloons){
                maxBalloons = (mp2[ch]/mp[ch]);
            }
        }
        return maxBalloons;
    }
};
