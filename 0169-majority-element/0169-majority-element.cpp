class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate = nums[0];
        int cnt = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] == candidate) cnt++;
            else cnt--;
            if(cnt == 0){
                candidate = nums[i];
                cnt++;
            }
        }

        return candidate;
    }
};