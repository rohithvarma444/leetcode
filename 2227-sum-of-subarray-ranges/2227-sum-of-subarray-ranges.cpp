class Solution {
public:
    void findNge(const vector<int> &nums, vector<int> &nge) {
        int n = nums.size();
        stack<int> st;
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPge(const vector<int> &nums, vector<int> &pge) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNse(const vector<int> &nums, vector<int> &nse) {
        int n = nums.size();
        stack<int> st;
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPse(const vector<int> &nums, vector<int> &pse) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n), pge(n), nse(n), pse(n);

        findNge(nums, nge);
        findPge(nums, pge);
        findNse(nums, nse);
        findPse(nums, pse);

        long long maxSum = 0, minSum = 0;

        for (int i = 0; i < n; ++i) {
            long long leftCountMax = i - pge[i];
            long long rightCountMax = nge[i] - i;
            maxSum += (long long)nums[i] * leftCountMax * rightCountMax;

            long long leftCountMin = i - pse[i];
            long long rightCountMin = nse[i] - i;
            minSum += (long long)nums[i] * leftCountMin * rightCountMin;
        }

        return maxSum - minSum;
    }
};
