//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/approximate/write-a-checker/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    //cout<<"n="<<n<<endl;
    vector<pair<string,int>>v1;
    vector<pair<int,int>>v2;
    vector<pair<string,int>>v3;
    vector<pair<string,int>>v4;
    for(int i=0;i<n;i++){
        string a,c,d;
        int b;
        cin>>a>>b>>c>>d;
        v1.push_back({a,i+1});
        v2.push_back({b,i+1});
        v3.push_back({c,i+1});
        v4.push_back({d,i+1});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    sort(v4.begin(),v4.end());

    map<pair<int,int>,int>m1;
    vector<pair<int,int>>lis;
    for(int i=1;i<=(n-1);i++){
    	//cout<<"shub";
        int j=i+1;
        while(v1[i-1].first==v1[j-1].first){
        	//cout<<"A";
            lis.push_back({v1[i-1].second,v1[j-1].second});
            j++;
        }
        j=i+1;
        while(v2[i-1].first==v2[j-1].first){
        	//cout<<"B";
            lis.push_back({v2[i-1].second,v2[j-1].second});
            j++;
        }
        j=i+1;
        while(v3[i-1].first==v3[j-1].first){
        	//cout<<"C";
            lis.push_back({v3[i-1].second,v3[j-1].second});
            j++;
        }
        j=i+1;
        while(v4[i-1].first==v4[j-1].first){
        	//cout<<"D";
            lis.push_back({v4[i-1].second,v4[j-1].second});
            j++;
        }
    }
    sort(lis.begin(),lis.end());
    unique(lis.begin(),lis.end());
    cout<<lis.size()<<endl;
    for(auto x:lis){
        //cout<<"hey ";
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    solve();
}
