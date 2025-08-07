class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int close = 0;
        int ans = 0;
        for(auto it: s){
            if(it == '(') open++;
            else if ( it == ')') close++;
            ans = max(ans,open-close);
        }

        return ans;
    }
};