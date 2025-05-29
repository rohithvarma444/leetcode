class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> freq;

        for(auto it: nums) freq[it]++;

        priority_queue<pair<int,int>> pq;
        for(auto it: freq) pq.push({it.second,it.first});

        vector<int> ans;

        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};