class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> left(N + 1), right(N + 1);

        // Step 1: Generate subset sums for left and right halves
        for (int mask = 0; mask < (1 << N); ++mask) {
            int leftSum = 0, rightSum = 0, count = 0;

            for (int j = 0; j < N; ++j) {
                if (mask & (1 << j)) {
                    count++;
                    leftSum += nums[j];
                    rightSum += nums[j + N];
                }
            }

            left[count].push_back(leftSum);
            right[count].push_back(rightSum);
        }

        // Step 2: Sort all vectors in right to binary search later
        for (int i = 0; i <= N; ++i) {
            sort(right[i].begin(), right[i].end());
        }

        int res = INT_MAX;

        // Step 3: Consider all splits of size i (left) and N - i (right)
        for (int i = 0; i <= N; ++i) {
            for (int a : left[i]) {
                int j = N - i;
                vector<int>& rvec = right[j];

                int target = totalSum / 2 - a;

                // Manual binary search to find closest value to 'target'
                int lo = 0, hi = rvec.size() - 1;
                while (lo <= hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (rvec[mid] < target) lo = mid + 1;
                    else hi = mid - 1;
                }

                // Now check both lo and hi to see which gives minimal diff
                if (lo < rvec.size()) {
                    int b = rvec[lo];
                    res = min(res, abs(totalSum - 2 * (a + b)));
                }
                if (hi >= 0) {
                    int b = rvec[hi];
                    res = min(res, abs(totalSum - 2 * (a + b)));
                }
            }
        }

        return res;
    }
};