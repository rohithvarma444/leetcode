class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        int cnt = 0;
        int ans = 0;
        
        while(right < n){
            if(nums[right] == 0){
                while(cnt >= k && left <= right){
                    if(nums[left] == 0){
                        cnt--;
                    }
                    left++;
                }
                if(cnt < k){
                    cnt++;
                }
            }

            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};