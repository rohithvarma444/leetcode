class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        int sum = 0;
        int ans = 0;
        mpp[0] = 1;

        int right = 0;
        while(right < n){
            sum += nums[right];
            int val = sum - k;

            if(mpp.find(val) != mpp.end()){
                ans += mpp[val];
            }
            mpp[sum]++;
            right++;
        }

        return ans;
    }
};