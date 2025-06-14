class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        
        for (int task : tasks) {
            freq[task]++;
        }

        int rounds = 0;

        for (auto& [difficulty, count] : freq) {
            if (count == 1) {
                return -1;
            }

            if (count % 3 == 0) {
                rounds += count / 3;
            } else if (count % 3 == 1) {
                rounds += (count - 4) / 3 + 2;
            } else if (count % 3 == 2) {
                rounds += count / 3 + 1;
            }
        }

        return rounds;
    }
};