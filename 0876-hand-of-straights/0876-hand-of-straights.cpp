class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) freq[card]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it : freq) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            int start = pq.top();

            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if (freq[curr] == 0) return false;

                freq[curr]--;
                if (freq[curr] == 0 && curr == pq.top()) {
                    pq.pop(); 
                }
            }
            while (!pq.empty() && freq[pq.top()] == 0) {
                pq.pop();
            }
        }

        return true;
    }
};