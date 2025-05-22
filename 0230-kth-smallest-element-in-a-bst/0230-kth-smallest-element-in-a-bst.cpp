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
    void helper(TreeNode* root,vector<int> &ans){
        if(root == nullptr) return;

        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        helper(root,ans);
        int n = ans.size();
        if (k <= 0 || k > ans.size()) return -1;
        return ans[k-1];
    }
};