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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newN = new TreeNode(val);
        if(root == nullptr) return newN;

        TreeNode* curr = root;

        while(curr != nullptr){
            if(curr->val > val && curr->left != nullptr){
                curr = curr->left;
            }

            if(curr->val < val && curr->right != nullptr){
                curr = curr->right;
            }

            if(curr->left == nullptr && curr->val > val){
                curr->left = newN;
                return root;
            }

            if(curr->right == nullptr && curr->val < val){
                curr->right = newN;
                return root;
            }
        }

        return root;
    }
};