class StockSpanner {
public:
    stack <pair<int,int>> st;
    int size;
    StockSpanner() {
        size = 0;
    }
    
    int next(int price) {
        size++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        
        int ans = st.empty()? size: size - st.top().second;
        st.push({price,size});

        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */