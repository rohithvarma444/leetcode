class Solution {
public:
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx) {
        if(start > end) return nullptr;

        int curr = preorder[idx++];
        TreeNode* root = new TreeNode(curr);

        int pos = search(inorder, start, end, curr);

        root->left = buildTreeHelper(preorder, inorder, start, pos - 1, idx);
        root->right = buildTreeHelper(preorder, inorder, pos + 1, end, idx);

        return root;
    }

    int search(vector<int> &inorder, int start, int end, int value) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == value) return i;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};