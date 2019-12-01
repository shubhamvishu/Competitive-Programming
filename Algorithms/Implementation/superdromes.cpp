//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/killjee-and-superdromes-037940f6/description/

#include<bits/stdc++.h>
 using namespace std;
 set<long>s1;
 bool ispalin(string s){
     for(int i=0,j=s.length()-1;i<j;i++,j--){
         if(s[i]!=s[j]) return false;
     }
     return true;
 }
 long calc(string s){
     int i=0;
     while(s[i]==0)i++;
     int j=0;
     long sum=0;
     for(int k=i;k<s.length();k++){
         if(s[k]=='1')
            sum+=pow(2,j);
        j++;    
     }
     return sum;
 }
 void func(string str,int l){
     if(l>21) return;
     if(str[0]!='0'){
         long x=calc(str);
        if(ispalin(to_string(x)))
        s1.insert(x);
     }
     func("1"+str+"1",l+2);
     func("0"+str+"0",l+2);
     return;
 }
 int main(){
     long n,q;
     cin>>q;
     func("0",1);
     func("00",2);
     func("1",1);
     func("11",2);
     while(q--){
         cin>>n;
         cout<<distance(s1.begin(),s1.upper_bound(n));
         cout<<" ";
     }
 }