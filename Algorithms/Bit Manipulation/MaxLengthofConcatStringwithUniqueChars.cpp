//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int>bitmap;
        vector<pair<int,int>>bitmask;
        for(auto str : arr){
            int num = 0;
            for(char ch : str){
                if(num&(1<<(ch-'a'))){
                    num = -1;
                    break;
                }
                num |= 1<<(ch-'a');
            }
            bitmap.push_back(num);
        }
        int maxL = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < bitmask.size(); j++){
                auto kp = bitmask[j];
                if(!((kp.first)&(bitmap[i]))){
                    bitmask.push_back({(kp.first)|(bitmap[i]), kp.second + arr[i].length()});
                    if((kp.second + arr[i].length()) > maxL){
                        maxL = kp.second + arr[i].length();
                    }
                }
            }
            if(bitmap[i]!=-1){
                bitmask.push_back({bitmap[i],arr[i].length()});
                if(arr[i].length() > maxL){
                    maxL = arr[i].length();
                }
            }

        }
        return maxL;
    }
};
