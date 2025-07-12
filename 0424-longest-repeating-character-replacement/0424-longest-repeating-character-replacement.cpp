class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int left = 0, right = 0, maxFreq = 0, maxi = 0;

        while (right < s.size()) {
            mpp[s[right]]++;
            maxFreq = max(maxFreq, mpp[s[right]]);  

            while ((right - left + 1) - maxFreq > k) {
                mpp[s[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};