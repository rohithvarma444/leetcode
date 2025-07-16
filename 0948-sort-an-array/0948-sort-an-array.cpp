class Solution {
public:
    void conquer(vector<int> &nums,int left,int right,int mid){
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while( i <= mid ){
            temp.push_back(nums[i++]);
        }

        while( j <= right){
            temp.push_back(nums[j++]);
        }

        int currIdx = 0;
        for(int i = left; i <= right; i++){
            nums[i] = temp[currIdx++];
        }
    }
    void divide(vector<int> &nums, int left, int right){
        if(left < right){
            int mid = left + (right-left)/2;
            divide(nums,left,mid);
            divide(nums,mid+1,right);
            conquer(nums,left,right,mid);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        divide(nums,left,right);

        return nums;
    }
};