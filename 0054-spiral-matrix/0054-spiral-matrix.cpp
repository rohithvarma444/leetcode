class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};  
        
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, down = m - 1;
        
        while (left <= right && top <= down) {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= down; i++)
                ans.push_back(matrix[i][right]);
            right--;

            if (top <= down) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }

            if (left <= right) {
                for (int i = down; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        
        return ans;
    }
};