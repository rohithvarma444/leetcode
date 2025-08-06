class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp;
        
        k = k % n;
        if(k == 0) return;
        for(int i = 0; i < n-k; i++){
            temp.push_back(nums[i]);
        }

        int currIdx = 0;
        for(int i = n-k; i < n; i++){
            nums[currIdx++] = nums[i];
        }

        for(int i = 0; i < n-k; i++){
            nums[currIdx++] = temp[i];
        }



    
    }
};