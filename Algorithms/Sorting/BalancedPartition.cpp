//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/balanced-partition-818edecd/

#include<bits/stdc++.h>
using namespace std;
string solve(){
        int n,x,y,h;
        cin>>n;
        vector<pair<int,int>>v1;
        vector<int>v2;
        for(int i = 0; i < n; i++){
            cin>>x>>y>>h;
            v1.push_back({y-x,h});
            v2.push_back(y-x);
        }
        unique(v2.begin(),v2.end());
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        int arr1[n],arr2[n];
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        int currsum = 0;
        for(int i = 0; i < n; i++) currsum+=v1[i].second,arr1[i]=currsum;
        currsum = 0;
        for(int j = n-1; j >=0; j--) currsum+=v1[j].second,arr2[j]=currsum;

        for(int i = 0; i < n-1; i++){
            if(v1[i].first==v1[i+1].first) continue;
            if(arr1[i]==arr2[i+1]) return "YES";
        }
        for(int i = 1;i < n-1; i++){
            int c=v1[i].first;
            int a=0,sum1=0,sum2=0;
            while(v1[a].first!=c) {
                sum1+=v1[a].second;
                a++;
            }
            a=n-1;
            while(v1[a].first!=c) {
                sum2+=v1[a].second;
                a--;
            }
            if(sum1==sum2){
                return "YES";
            }
        }
        return "NO";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}
