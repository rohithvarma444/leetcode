class Solution {
public:
    bool helper(TreeNode* root, int k, unordered_set<int>& seen) {
        if (!root) return false;

        if (seen.count(k - root->val)) return true;

        seen.insert(root->val);

        return helper(root->left, k, seen) || helper(root->right, k, seen);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return helper(root, k, seen);
    }
};