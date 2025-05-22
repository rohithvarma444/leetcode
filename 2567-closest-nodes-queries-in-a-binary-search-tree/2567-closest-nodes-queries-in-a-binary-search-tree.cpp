/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedVals;
        inorder(root, sortedVals);

        vector<vector<int>> result;

        for (int q : queries) {
            int floor = -1, ceil = -1;

            auto it = lower_bound(sortedVals.begin(), sortedVals.end(), q);
            if (it != sortedVals.end()) ceil = *it;
            if (it != sortedVals.begin()) {
                if (it == sortedVals.end() || *it != q) --it;
                floor = *it;
            } else if (*it == q) {
                floor = *it;
            }

            result.push_back({floor, ceil});
        }

        return result;
    }

    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};