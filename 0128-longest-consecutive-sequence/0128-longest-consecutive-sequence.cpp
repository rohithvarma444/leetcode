class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
        }

        int prev = pq.top();
        pq.pop();

        int cnt = 1;
        int ans = 1;

        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (curr == prev) {
                continue; 
            }
            if (curr == prev + 1) {
                cnt++; 
            } else {
                cnt = 1;
            }

            ans = max(ans, cnt);
            prev = curr;
        }

        return ans;
    }
};