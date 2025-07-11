class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int n = s.size();
        for(int i = 0; i < n; i++){
            string ans = goal.substr(i,n-i) + goal.substr(0,i) ;
            cout << ans << endl;
            if(ans == s) return true;
        }

        return false;
    }
};