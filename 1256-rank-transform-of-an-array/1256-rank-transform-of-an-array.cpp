class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans(n, -1);
        map<int, int> mpp;  

        for (auto val : arr) mpp[val] = 0;

        int rank = 1;
        for (auto& [val, _] : mpp) {
            mpp[val] = rank++;
        }

        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }

        while (!pq.empty()) {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans[idx] = mpp[val];
        }

        return ans;
    }
};