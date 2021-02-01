//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=1;
        string str,res;
        for(int i=0;i<(2*s.length()+1);i++)
         str.append("$");
        vector<int> v1(2*s.length()+1,1);
        for(int i=1,j=0;j<s.length();i+=2,j++)
        {
            str[i]=s[j];
        }
        //cout<<str<<endl;
       int i=1,a1,a2;
        while(i<str.length()-1 && (str.length()-i)>maxlen/2)
        {   int curmax=1,start=i,end=i;
            for(int m=i,n=i;m>=0 && n<str.length();m--,n++)
            {
                if(str[m]==str[n])
                {
                    curmax+=2;
                    start=m;end=n;
                    if((end-start+1)>maxlen)
                     {maxlen=end-start+1;
                      a1=start;a2=end;
                     }
                }
                else break;
            }
            v1[i]=end-start+1;
            int m=i-1,n=i+1,sum=0,next=i+1;
            for(;sum<(v1[i]/2);m--,n++)
            {
                sum+=v1[m];
                if(sum<(v1[i]/2)){
                    v1[n]=v1[m];
                }
                else{
                    next=n;
                    break;
                }
            }
            i=next;
        }
        //cout<<"length:"<<maxlen/2<<endl;
        for(int k=a1;k<=a2;k++)
        {
            if(str[k]!='$')
             res.append(1,str[k]);
        }
        return res;
    }
};
