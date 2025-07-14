class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(auto it: num){
            
            while(!st.empty() && k > 0 && it - '0' < st.top() - '0'){
                st.pop();
                k--;
            }
            st.push(it);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }

        while(ans.size()!= 0 && ans.back()=='0'){
            ans.pop_back();
        }

        if(ans.size() == 0) return "0";
        reverse(ans.begin(),ans.end());

        
        return ans;

    }
};