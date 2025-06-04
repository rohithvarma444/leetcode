class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int maxSize = n - numFriends + 1;

        if(n == 1) return word;
        if(numFriends == 1) return word;

        priority_queue<string> st;

        for(int i = 0; i < n; i++){
            st.push(word.substr(i,maxSize));
        }
        return st.top();
    }
};