//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        map<char,int>m1,m2;
        map<char,int>::iterator it;
        vector<int>v1;
        int count=0,minn=INT_MAX,a1=0;
        for(char c:s2){m2[c]++;}
        count=m2.size();
        for(int i=0;i<s1.length();i++) {
            m1[s1[i]]++;
            if(m2[s1[i]])
             v1.push_back(i);
        }
        bool b=true;
        for(char c:s2)
        {
            m1[c]--;
            if(m1[c]<0)
             b=false;
        }
        if(!b)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else{
            m1.clear();
            int k=0;
            int i=v1[k++],last,j=0,c=0;
            last=i;
            while(k<v1.size() && s1.length()-i>=s2.length())
            {    
                j=last;
                while(j<s1.length() && c<count)
                {
                    
                    m1[s1[j]]++;
                    if(m2[s1[j]] && m1[s1[j]]==m2[s1[j]])
                     c++;
                    if(c==count) break;
                    j++; 
                }
                
                if(c==count){
                    if((j-i+1)<minn)
                    {
                        minn=(j-i+1);
                        a1=i;
                    }
                    if(m1[s1[i]]>m2[s1[i]])
                    {
                        m1[s1[i]]--;
                        last=j;
                    }
                    else{
                        m1[s1[i]]--;
                        last=j+1;
                        c--;
                       }
                }
                else break;

                i=v1[k++];
            }
            cout<<s1.substr(a1,minn)<<endl;
        }
    }
    return 0;      
}
