/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*> &mpp){

        vector<Node*> neigh;
        Node* clone = new Node(node->val);
        mpp[node] = clone;
        if(node->neighbors.size() == 0) return clone;
        for(auto it: node->neighbors){
            if(mpp.find(it) == mpp.end()){
                neigh.push_back(dfs(it,mpp));
            }
            else neigh.push_back(mpp[it]);
        }

        clone->neighbors = neigh;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mpp;
        if(node == nullptr) return nullptr;

        if(node->neighbors.size() == 0){
            return new Node(node->val);
        }

        return dfs(node,mpp);
    }
};