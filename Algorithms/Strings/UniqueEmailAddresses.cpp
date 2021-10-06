//https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<pair<string,string>,int>mp;
        int count = 0;
        for(auto email : emails){
            string local_name = "";
            for(int i = 0; email[i]!='+' && email[i]!='@'; i++){
                if(email[i]!='.') local_name+=email[i];
            }
            int pos = email.find("@");
            string domain_name = email.substr(pos+1);
            if(!mp[{local_name, domain_name}]){
                count++;
                mp[{local_name, domain_name}]++;
            }
        }
        return count;
    }
};
