#include<bits/stdc++.h>
using namespace std;
unsigned long maxl;
long minn(long a,long b){
    return (a<=b)?a:b;
}
bool isSpecial(long n){
    while(n){
        if(n%10!=2 && n%10!=5)
        return false;
        n/=10;
    }
    return true;
}
long convert(long arr[],long c){
    long p=1,num=0;
    for(long i=c;i>=0;i--){
        num+=arr[i]*p;
        p*=10;
    }
    return num;
}
long nextSpecial(long n){
    if(isSpecial(n))
     return n;
    long temp=n;
    long c=0;
    while(temp){
        c++;
        temp/=10;
    }
    temp=n;
    long arr[c+1],pos=0;
    arr[0]=0;
    for(long i=c;i>=1;i--){
        arr[i]=temp%10;
        temp/=10;
    }
    for(long i=1;i<=c;i++){
    	if(arr[i]==2 || arr[i]==5 ) continue;
    	else if(arr[i]<=2) {
    		arr[i]=2;
    		pos=i+1;
    		break;
    	}
    	else if(arr[i]<=5){
    		arr[i]=5;
    		pos=i+1;
    		break;
    	}
    	else{
    		arr[i]=2;
    		pos=i+1;
    		long t=i-1;
    		while(arr[t]==5){
    			t--;
    		}
    		if(arr[t]==2)
    		{arr[t]=5;for(long j=t+1;j<=c;j++)arr[j]=2;}
    		else {arr[t]=2;for(long j=1;j<=c;j++)arr[j]=2;}
    		break;
    	}
    }
    for(int i=pos;i<=c;i++)
    arr[i]=2;
    return convert(arr,c);
    
}
long func(long l,long r){
    long sum=0,next;
    for(long i=l;i<=r;){
        next=minn(nextSpecial(i),r);
        sum+=(next-i+1)*nextSpecial(i);
        i=next+1;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long l,r;
        cin>>l>>r;
        cout<<func(l,r)<<endl;
    }
}