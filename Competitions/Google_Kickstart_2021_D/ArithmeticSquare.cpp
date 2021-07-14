//https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int getAP(vector<ull>v1){
    return ((v1[1]-v1[0])==(v1[2]-v1[1])) + ((v1[4]-v1[2])==(v1[7]-v1[4])) + ((v1[6]-v1[5])==(v1[7]-v1[6])) + ((v1[3]-v1[0])==(v1[5]-v1[3]));
}

int solve(){
    vector<ull>v1(8);
    for(int i = 0; i < 8; i++){
        cin>>v1[i];
    }
    map<ull,ull>m1;
    ull maxx = 0;
    if((v1[0]+v1[7])%2==0) {
        m1[(v1[0]+v1[7])/2]++;
        if(m1[(v1[0]+v1[7])/2] > maxx) maxx = m1[(v1[0]+v1[7])/2];
    }
    if((v1[2]+v1[5])%2==0) {
        m1[(v1[2]+v1[5])/2]++;
        if(m1[(v1[2]+v1[5])/2] > maxx) maxx = m1[(v1[2]+v1[5])/2];
    }
    if((v1[1]+v1[6])%2==0) {
        m1[(v1[1]+v1[6])/2]++;
        if(m1[(v1[1]+v1[6])/2] > maxx) maxx = m1[(v1[1]+v1[6])/2];
    }
    if((v1[3]+v1[4])%2==0) {
        m1[(v1[3]+v1[4])/2]++;
        if(m1[(v1[3]+v1[4])/2] > maxx) maxx = m1[(v1[3]+v1[4])/2];
    }
    return getAP(v1) + maxx;
}

int main(){
    ull t,t1;
    cin>>t;
    t1=t;
    while(t--){
        cout<<"Case #"<<(t1-t)<<": "<<solve()<<'\n';
    }
}
