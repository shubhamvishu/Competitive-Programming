//https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length()==1) return "";
        bool b = false;
        for(int i = 0 ; i < palindrome.length() ; i++){
            if(palindrome[i]!='a' && !(palindrome.length()%2 && i==palindrome.length()/2)) {
                palindrome[i]='a';
                b = true;
                break;
            }
        }
        if(!b) palindrome[palindrome.length()-1] = 'b';
        return palindrome;
    }
};
