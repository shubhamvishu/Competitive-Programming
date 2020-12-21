//https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        stringstream ss1(str);
        int x=0;
        ss1>>skipws>>x;
        return x;
    }
};
