class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;

        priority_queue<int> pq;
        for(auto it: nums) pq.push(it);

        int val = -1;

        while(k > 0){
            val = pq.top();
            pq.pop();
            k--;
        }

        return val;
        
    }
};