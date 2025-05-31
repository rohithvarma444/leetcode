class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        unordered_set <string> st (bank.begin(),bank.end());
        st.erase(startGene);
        q.push({startGene,0});

        char choice[] = {'A','C','G','T'};
        while(!q.empty()){
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(curr == endGene) return steps;
            for(int i=0;i<curr.size();i++){
                char original = curr[i];
                for(int j=0;j<4;j++){
                    curr[i]=choice[j];
                    if(st.find(curr) != st.end()){
                        q.push({curr,steps+1});
                        st.erase(curr);
                    }
                }
                curr[i] = original;
            }
        }
        return -1;
    }
};