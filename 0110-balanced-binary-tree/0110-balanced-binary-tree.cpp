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
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);

        return max(left,right);
    }
    bool helper(TreeNode* root){
        if(root == nullptr) return true;

        int left = height(root->left);
        int right = height(root->right);

        if(abs(left - right) > 1) return false;
        
        return helper(root->left) && helper(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};