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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        map <int,map<int,multiset<int>>> nodes;
        queue <pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr = q.front().first;
            auto hDist = q.front().second.first;
            auto level = q.front().second.second;
            q.pop();
            nodes[hDist][level].insert(curr->val);
            if(curr->left != nullptr) q.push({curr->left,{hDist-1,level+1}});
            if(curr->right != nullptr) q.push({curr->right,{hDist+1,level+1}});
        }

        


        for(auto it: nodes){
            vector<int> tmp;
            for(auto node: it.second){
                for(auto values: node.second){
                    tmp.push_back(values);
                }
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};