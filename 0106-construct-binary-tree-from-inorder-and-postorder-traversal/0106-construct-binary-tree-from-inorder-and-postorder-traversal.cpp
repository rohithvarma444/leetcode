class Solution {
public:
    TreeNode* treeBuilder(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx) {
        if (start > end) return nullptr;

        int curr = postorder[idx--];
        TreeNode* root = new TreeNode(curr);

        int pos = search(inorder, start, end, curr);

        root->right = treeBuilder(inorder, postorder, pos + 1, end, idx);  
        root->left = treeBuilder(inorder, postorder, start, pos - 1, idx);

        return root;
    }

    int search(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return treeBuilder(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};