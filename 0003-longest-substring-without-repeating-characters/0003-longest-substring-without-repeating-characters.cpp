class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        map<char,int> mpp;

        int ans = 0;

        while(right < n){
            mpp[s[right]]++;

            while(mpp[s[right]] > 1){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};