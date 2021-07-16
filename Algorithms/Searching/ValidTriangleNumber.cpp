//https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        int total = 0;
        for(int i = 0; i < N-1; i++){
            for(int j = i+1; j < N; j++){

                int start = j, end = N-1,maxcount=0;
                if(j<N-1 && nums[N-1]<(nums[i]+nums[j])){
                    total+=(N-1-j);
                }
                else{
                    while(start<=end){

                      int mid = (start+end)/2;
                          if(nums[mid]<(nums[i]+nums[j])){
                               start=mid+1;
                               maxcount =(mid-j);
                          }
                          else end=mid-1;
                    }
                    total+=maxcount;
                }

            }
        }
        return total;

    }
};
