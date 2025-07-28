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
    void flatten(TreeNode* root) {
        if(root == nullptr || root->left == nullptr && root->right == nullptr) return;

        TreeNode* temp = root->right;
        if(root->left != nullptr){
            flatten(root->left);
            root->right = root->left;
            root->left = nullptr;


            TreeNode* t = root;
            while(t->right != nullptr){
                t = t->right;
            }
            t->right = temp;
        }

        flatten(root->right);
    }
};