//https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1=coordinates[0][0],y1=coordinates[0][1];
        int x2=coordinates[1][0],y2=coordinates[1][1];
        double m,c;
        if((x2-x1)!=0){
            m=(double(y2-y1)/double(x2-x1));
            c=double(y1-(m*x1));
            for(auto v:coordinates)
                if(abs(v[1]-(m*v[0]+c))>1e-3)
                    return false;
        }
        else{  for(auto v:coordinates)
                if(v[0]!=x1) return false;
        }
        return true;
    }
};
