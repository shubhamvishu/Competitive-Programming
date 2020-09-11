#include <iostream>
using namespace std;
int k=1;
char solve(int n,string& s){
    int umap[26];
    memset(umap,0,sizeof(umap));
	int i=0;
	for(i=0;i<s.length();i++){
		umap[s[i]-'A']++;
		
	}
	return abs(umap['A'-'A']-umap['B'-'A'])==1?'Y':'N';
}
int main() {
	
	int t=0,n;
	string s;
    freopen("inputB.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cin>>s;
		cout<<"Case #"<<k++<<": "<<solve(n,s)<<'\n';
	}
	return 0;
}