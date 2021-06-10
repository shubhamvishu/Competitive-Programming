//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/benny-and-segments-marcheasy/

#include<bits/stdc++.h>
using namespace std;

string solve(){
    int n,l,xl,xr;
    cin>>n>>l;
    map<int, vector<int>>m1;
    map<int,int>m2;
    vector<int>v1;
    for(int i = 0; i < n ; i++){
        cin>>xl>>xr;
        if((xr-xl)<=l){
        	v1.push_back(xl);
        	v1.push_back(xr);
        	m1[xl].push_back(xr);
        	m2[xl]++,m2[xr]++;
        }

    }
    sort(v1.begin(),v1.end());
    unique(v1.begin(),v1.end());

    for(auto i:v1){
    	if(m2[i+l]){
    		auto it = m1.find(i);
    		int left=i,right=i;
    		while(it->first>=left && it->first<=right && it!=m1.end()){
    			for(int x=0;x<it->second.size();x++){
	    			if(it->second[x]<=(left+l) && it->second[x]>right){
	    				right=it->second[x];
	    			}
    			}
    			it++;
    		}
    		if(right==(i+l)) return "Yes";
    	}
    	else{
    		continue;
    	}
    }
    return "No";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
}
