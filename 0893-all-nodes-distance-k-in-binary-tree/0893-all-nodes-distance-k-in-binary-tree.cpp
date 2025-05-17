/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Populate the parent map for all nodes
    void parentMap(TreeNode* root, map<TreeNode*, TreeNode*>& mpp) {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        mpp[root] = nullptr;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                mpp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                mpp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr || target == nullptr) return {};

        map<TreeNode*, TreeNode*> parent;
        parentMap(root, parent);

        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int curr_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (curr_level == k) break;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                TreeNode* par = parent[curr];
                if (par && !visited[par]) {
                    visited[par] = true;
                    q.push(par);
                }
            }

            curr_level++;
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};