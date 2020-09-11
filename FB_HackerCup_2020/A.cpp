//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int k=1;
void solve(int n,char I[],char O[]){
	char res[n+1][n+1];
	int k=1;
	for(int j=0;j<n;j++){
		res[j][j]='Y';
		if(j-1>=0){
			res[j][j-1]=(O[j]=='Y' && I[j-1]=='Y')?'Y':'N';
		}
		if(j+1<n){
			res[j][j+1]=(O[j]=='Y' && I[j+1]=='Y')?'Y':'N';
		}
	}
	for(int i=2;i<n;i++){
		for(int j=0;j<n;j++){
			if(j-i>=0){
				res[j][j-i]=(res[j][j-i+1]=='Y' && O[j-i+1]=='Y' && I[j-i]=='Y')?'Y':'N';
			}
			if(j+i<n){
				res[j][j+i]=(res[j][j+i-1]=='Y' && O[j+i-1]=='Y' && I[j+i]=='Y')?'Y':'N';
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<res[i][j];
		}cout<<'\n';
	}
}
int main() {
	
	int t,n;
	char I[100],O[100];
	freopen("inputA.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) cin>>I[i];
		for(int i=0;i<n;i++) cin>>O[i];
		cout<<"Case #"<<k++<<":"<<'\n';
		solve(n,I,O);
	}
	return 0;
}