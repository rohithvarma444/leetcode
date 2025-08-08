class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int currLow = 0;
        sort(intervals.begin(),intervals.end());
        int low = intervals[0][0];
        int high = intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= high){
                if(high < intervals[i][1]) high = intervals[i][1];
            }
            else{
                ans.push_back({low,high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }

        ans.push_back({low,high});
        return ans;
    }
};