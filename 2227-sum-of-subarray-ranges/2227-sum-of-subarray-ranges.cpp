class Solution {
public:
    void findPGE(vector<int>& nums, vector<int>& pge, int n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNGE(vector<int>& nums, vector<int>& nge, int n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPSE(vector<int>& nums, vector<int>& pse, int n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNSE(vector<int>& nums, vector<int>& nse, int n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n), nge(n), pse(n), nse(n);

        findPGE(nums, pge, n);
        findNGE(nums, nge, n);
        findPSE(nums, pse, n);
        findNSE(nums, nse, n);

        long long maxi = 0, mini = 0;
        for (int i = 0; i < n; i++) {
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxi += leftMax * rightMax * (long long)nums[i];

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            mini += leftMin * rightMin * (long long)nums[i];
        }

        return maxi - mini;
    }
};