class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char, vector<char> , greater<char>> hash;
        unordered_map <char, vector<int>> m;
        vector<bool> v(n,true);

        for(int i = 0; i < n; i++){
            if(s[i] != '*'){
                hash.push(s[i]);
                m[s[i]].push_back(i);
            }
            else{
                char smallestChar = hash.top();
                hash.pop();

                int lastOcc = m[smallestChar].back();
                m[smallestChar].pop_back();
                v[lastOcc] = false;
                v[i] = false;
            }
        }


        string ans = "";
        for(int i =0; i < n; i++){
            if(v[i]) ans += s[i];
        }
        return ans;
    }
};