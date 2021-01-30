//https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {

	    int temp=n;
        vector<long>v1(10000,INT_MAX);
        vector<long>vec;
        v1[1]=1,v1[2]=2,v1[3]=3,v1[4]=1;
        vec.push_back(1);
        vec.push_back(4);
        int offset=5,curr=4;
        for(int i=5;i<=n;i++){

            if(i==(curr+offset)){
                v1[i]=1;
                vec.push_back(i);
                curr=i;
                offset+=2;
            }
            else{
                for(int j=0;j<vec.size();j++){
                    if(v1[vec[j]]+v1[i-vec[j]]<v1[i])
                        v1[i]=(v1[vec[j]]+v1[i-vec[j]]);
                }
            }
        }
        return v1[n];
    }
};
