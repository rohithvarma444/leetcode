class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];

        while(left <= right){
            int mid = left + (right-left)/2;

            if(mid %2 == 0){
                if(nums[mid] != nums[mid+1]){
                    if(mid != 0 && nums[mid] != nums[mid-1]) return nums[mid];
                    right = mid -1;
                }
                else left = mid + 1;
            }
            else{
                if(nums[mid] != nums[mid-1]){
                    if(mid != n && nums[mid] != nums[mid+1]) return nums[mid];
                    right = mid -1;
                }
                else left = mid + 1;
            }
        }

        return -1;
    }
};