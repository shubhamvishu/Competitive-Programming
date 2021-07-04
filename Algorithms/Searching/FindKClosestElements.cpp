//https://leetcode.com/explore/featured/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/

class Solution {
public:
    int bs(vector<int>& arr, int x){
        int N = arr.size();
        int i = 0, j= arr.size()-1,mid=0;
        while(i<j){
            mid = (i+j)/2;
            if(arr[mid]==x){
                break;
            }
            if(x<arr[mid]) j=mid-1;
            if(x>arr[mid]) i=mid+1;
        }
        if(arr[mid]==x){
            return mid;
        }
        return i;

    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int S=arr.size();
        if(x<arr[0] ){
            vector<int>v(k);
            copy(arr.begin(),arr.begin()+k,v.begin());
            return v;
        }if(arr[arr.size()-1]<x) {
            vector<int>v(k);
            copy(arr.begin()+S-k,arr.end(),v.begin());
            return v;
        }
        auto p = bs(arr,x);
        int i=0,j=0,ct=0;
        if(arr[p]==x){
            i=p,j=p;
        }
        else if(arr[p]<x){
            i=p,j=p+1;
        }
        else{
            i=p-1,j=p;
        }
        list<int>l;
        for(auto a:l){
            cout<<a<<endl;
        }
        while(ct<k){
            if(i==j){
                l.push_front(arr[i]);
                i--;
                j++;
                ct++;
            }
            else if(i>=0 && j<S && (x-arr[i])<=(arr[j]-x)){
                l.push_front(arr[i]);
                i--;
                ct++;

            }
            else if(j<S && i>=0 && (x-arr[i])>(arr[j]-x)){
                l.push_back(arr[j]);
                j++;
                ct++;
            }
            else if(i<0){
                l.push_back(arr[j]);
                j++;
                ct++;
            }
            else{
                l.push_front(arr[i]);
                i--;
                ct++;
            }
        }
        vector<int>res;
        for(auto a:l){
            res.push_back(a);
        }
        return res;
    }
};
