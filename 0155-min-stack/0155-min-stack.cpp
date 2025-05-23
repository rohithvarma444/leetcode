class MinStack {
public:
    vector<pair<int,int>> st;
    int mini = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        mini = min(mini,val);
        st.push_back({val,mini});
    }
    
    void pop() {
        auto [val, currMin] = st.back();
        st.pop_back();
        if(!st.empty()) mini = st.back().second; 
        else mini = INT_MAX;
    }
    
    int top() {
        auto [val, currMin] = st.back();
        return val;
    }
    
    int getMin() {
        auto [val, currMin] = st.back();
        return currMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */