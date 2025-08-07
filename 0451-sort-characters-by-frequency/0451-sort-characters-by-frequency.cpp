class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for (auto it : s) mpp[it]++;

        vector<pair<int, char>> freqVec;
        for (auto it : mpp) {
            freqVec.push_back({it.second, it.first});
        }

        sort(freqVec.rbegin(), freqVec.rend());

        string ans = "";
        for (auto it : freqVec) {
            ans += string(it.first, it.second); 
        }

        return ans;
    }
};
