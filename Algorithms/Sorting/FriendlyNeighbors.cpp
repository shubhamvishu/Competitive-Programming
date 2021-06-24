//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/choose-one-c4672347/

#include<bits/stdc++.h>
using namespace std;
int mod(int num){
    if(num<0) return -1*num;
    return num;
}
int solve(){
    int n,n2,N,s=0;
    cin>>n;
    n2=1;
    map<int,int>m1;
    map<int,vector<int>>m2;
    map<int,int>m3;
    vector<int>v1;
    while(n2<=n){
        cin>>N;
        s+=N;
        int arr[N];
        for(int i = 1; i <= N ; i++){
            cin>>arr[i];
            m1[arr[i]]=n2;
            m2[n2].push_back(arr[i]);
            v1.push_back(arr[i]);
        }
        n2++;
    }
    sort(v1.begin(),v1.end());
    int i=0,j=0,count=0,ans=INT_MAX,temp=-1;
    while(i<s){
        if(m3[m1[v1[i]]]<1){
            count++;
        }
        if(i!=temp){
            m3[m1[v1[i]]]++;
            temp=i;
        }

        if(count>=n){
            if(mod(v1[i]-v1[j]) < ans)
                ans=mod(v1[i]-v1[j]);
            m3[m1[v1[j]]]--;
            if(m3[m1[v1[j]]]<1) {
                count--;
            }
            j++;
        }
        if(count<n){
            i++;
        }

    }
    return 2*ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}
