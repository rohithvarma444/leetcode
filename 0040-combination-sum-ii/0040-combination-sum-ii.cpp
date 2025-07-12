class Solution {
public:
    void findCombinations(int index, int sum, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        if (index == candidates.size() || sum > target) {
            return;
        }

        current.push_back(candidates[index]);
        findCombinations(index + 1, sum + candidates[index], candidates, target, current, ans);
        current.pop_back(); 

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }

        findCombinations(index + 1, sum, candidates, target, current, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); 
        findCombinations(0, 0, candidates, target, current, ans);
        return ans;
    }
};