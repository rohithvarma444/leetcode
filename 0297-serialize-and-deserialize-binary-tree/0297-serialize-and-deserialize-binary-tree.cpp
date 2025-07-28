class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#,";

        queue<TreeNode*> q;
        q.push(root);

        string data = "";

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                data += "#,";
                continue;
            }

            data += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }

        return data;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        string str;
        stringstream s(data);
        queue<TreeNode*> q;

        getline(s, str, ',');
        if (str == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            // LEFT CHILD
            if (getline(s, str, ',')) {
                if (str != "#") {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    curr->left = leftNode;
                    q.push(leftNode);
                }
            }

            if (getline(s, str, ',')) {
                if (str != "#") {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    curr->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};
