//https://www.hackerrank.com/challenges/attribute-parser/problem

#include <bits/stdc++.h>
using namespace std;
stack<string> st;
map<string,string>m1;

int main() {
    
    int m,n;
    cin>>m>>n;
    string s;
    for(int i=0;i<m;i++)
    {   
	    if(i==0) cin.ignore();
        getline(cin,s,'\n');
        stringstream ss(s);
        string str1;
        if(s[1]!='/')
        {   char c1;
            ss>>c1;
            getline(ss,str1,'>');
            //cout<<endl<<"s1= "<<str1<<endl;
            stringstream ss1(str1);
            string tag,temp;
            getline(ss1,tag,' ');
            //cout<<"tag="<<tag<<" "<<endl;
            if(st.empty())
            {
                st.push(tag);
                //cout<<endl<<"tp1="<<tag;
            }
            else{
                string add=st.top();
                add.append(".");
                add.append(tag);
                st.push(add);
                //cout<<endl<<"tp2="<<add;
            }
            while(getline(ss1,temp,'"'))
            {   
                string attname,attval;
                stringstream ss2(temp);
                ss2>>skipws>>attname;
                stringstream ss3(attname);
                getline(ss3,attname,'=');
                //cout<<"Attname="<<attname<<" ";
                getline(ss1,temp,'"');
                stringstream ss4(temp);
                ss4>>skipws>>attval;
                //cout<<"Attval="<<attval<<endl;
                string top=st.top();
                m1[top.append("~").append(attname)]=attval;
                
            }
        }
        else{
          if(!st.empty())
          st.pop();
          //cout<<str1<<endl;
        }
    
    }   
    for(int i=0;i<n;i++)
    {   
        getline(cin,s,'\n');
        //cout<<"map["<<s<<"] ="<<m1[s]<<endl;
        if(m1[s].empty())
          cout <<"Not Found!"<<endl; 
        else
          cout<<m1[s]<<endl;  
    }
    return 0;
}

