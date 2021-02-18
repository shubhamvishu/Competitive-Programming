//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    vector<pair<int,int>>stock_span;
    int S;
    StockSpanner() {
        S=0;
    }

    int next(int price) {
        if(S==0){
            stock_span.push_back({price,1});
            ++S;
        }
        else{
            int i=S-1,ans=1;
            while(i>=0 && price>=stock_span[i].first){
                ans+=stock_span[i].second;
                i-=stock_span[i].second;
            }
            stock_span.push_back({price,ans});
            ++S;
        }
        return stock_span[S-1].second;
    }
};
