class StockSpanner {
private:
    stack<pair<int,int>>s;
    int cur_index;
public:
    StockSpanner() {
        cur_index=0;
    }
    
    int next(int price) {
        if(s.size()==0)
        {
            s.push({price,cur_index++});
            return 1;
        }
        while(!s.empty() && s.top().first<=price)
            s.pop();
        int ans;
        if(s.size()==0)
            ans= cur_index+1;
        else
            ans=(cur_index-s.top().second);
        s.push({price,cur_index++});
        return ans;
            
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */