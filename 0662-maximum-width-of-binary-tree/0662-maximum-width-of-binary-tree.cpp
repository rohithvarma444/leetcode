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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;


            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front().first;
                long long currIdx = q.front().second;
                q.pop();

                if(curr->left != nullptr) q.push({curr->left,2*(currIdx-mini)+ 1});
                if(curr->right != nullptr) q.push({curr->right,2*(currIdx-mini)+ 2});

                ans = max(ans, currIdx-mini+1);
            }
        }

        return ans;
    }
};