class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st(wordList.begin(),wordList.end());
        priority_queue<pair<int,string>, vector<pair<int,string>>,greater<>> pq;
        pq.push({1,beginWord});

        while(!pq.empty()){

            string currWord = pq.top().second;
            int steps = pq.top().first;
            pq.pop();

            if(currWord == endWord) return steps;

            for(int i = 0; i < currWord.size(); i++){
                string temp = currWord;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(st.find(temp) != st.end()){
                        pq.push({steps+1,temp});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};