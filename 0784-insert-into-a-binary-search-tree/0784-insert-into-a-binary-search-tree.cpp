class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newN = new TreeNode(val);

        if (root == nullptr)
            return newN;

        TreeNode* temp = root;
        while (true) {
            if (val < temp->val) {
                if (temp->left == nullptr) {
                    temp->left = newN;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == nullptr) {
                    temp->right = newN;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }

        return root;
    }
};