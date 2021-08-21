//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/


#include<bits/stdc++.h>
using namespace std;

char find_parent(char ch, map<char,char>&m1){
   if(ch==m1[ch]) return ch;
   return m1[ch] = find_parent(m1[ch],m1);
}

void union_sets(char ch1, char ch2,map<char,char>&m1){
   char parent1 = find_parent(ch1,m1);
   char parent2 = find_parent(ch2,m1);
   if(parent1!=parent2){
      if(parent1<=parent2){
         m1[parent2]=parent1;
      }
      else {
         m1[parent1]=parent2;
      }

   }
}

string Solution (string A, string C, string B) {
   // Write your code here
   map<char,char>m1;
   for(int i=0;i<26;i++){
      m1[i+'a']=(i+'a');
   }
   for(int i = 0; i < A.length(); i++){
      union_sets(A[i],B[i],m1);
   }
   string res = "";
   for(char c:C){
      res+=find_parent(c,m1);
   }
   return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string A;
    getline(cin, A);
    string B;
    getline(cin, B);
    string C;
    getline(cin, C);

    string out_;
    out_ = Solution(A, C, B);
    cout << out_;
}
