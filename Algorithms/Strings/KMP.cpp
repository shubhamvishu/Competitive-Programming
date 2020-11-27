#include<bits/stdc++.h>
using namespace std;
int* func(string pat,int* F){
	int i=0;
	F[0]=0;
	for(int i=1;i<pat.length();i++){
		int j=F[i-1];
		while(j>0 && pat[i]!=pat[j]) j=F[j-1];
		if(pat[i]==pat[j]) j++;
		F[i]=j;
	}
    return F;
}
vector<int> kmp(int* F,string pat,string text){
	
	vector<int>arr;
	int i=0,j=0;
	while(i<text.length()){
		if(text[i]==pat[j]){
			//cout<<"I="<<i<<" "<<j<<endl;
			i++;
			j++;
			
		}
		if(j==pat.length()){
				//cout<<"Found at "<<(i-j)<<endl;
				arr.push_back(i-j);
				j=F[j-1];
		}
		else if (i < text.length() && pat[j] != text[i]){
			if (j != 0) 
                j = F[j - 1]; 
            else
                i = i + 1; 
		}
	}
	return arr;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string text,pat;
    cin>>pat>>text;
    int *F=new int[pat.length()];
    memset(F,0,sizeof(F));
    F=func(pat,F);
	vector<int> indi=kmp(F,pat,text);
    cout<<indi.size()<<endl;
}
